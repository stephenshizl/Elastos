//=========================================================================
// Copyright (C) 2012 The Elastos Open Source Project
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//      http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//=========================================================================

#include "elastos/droid/systemui/statusbar/policy/KeyguardUserSwitcher.h"
#include "elastos/droid/systemui/statusbar/policy/CKeyguardUserSwitcherScrim.h"
#include "elastos/droid/systemui/statusbar/policy/UserSwitcherController.h"
#include "elastos/droid/systemui/statusbar/phone/CPhoneStatusBar.h"
#include "../R.h"
#include <elastos/droid/R.h>
#include <elastos/droid/view/LayoutInflater.h>
#include <elastos/droid/view/animation/AnimationUtils.h>
#include <elastos/core/Math.h>
#include <elastos/utility/logging/Logger.h>

using Elastos::Droid::Animation::CObjectAnimatorHelper;
using Elastos::Droid::Animation::IAnimator;
using Elastos::Droid::Animation::IObjectAnimatorHelper;
using Elastos::Droid::Animation::IValueAnimator;
using Elastos::Droid::SystemUI::Qs::Tiles::IUserDetailItemView;
using Elastos::Droid::SystemUI::StatusBar::Phone::CPhoneStatusBar;
using Elastos::Droid::View::EIID_IViewOnClickListener;
using Elastos::Droid::View::ILayoutInflater;
using Elastos::Droid::View::IViewPropertyAnimator;
using Elastos::Droid::View::LayoutInflater;
using Elastos::Droid::View::IViewGroup;
using Elastos::Droid::View::Animation::AnimationUtils;
using Elastos::Utility::Logging::Logger;

namespace Elastos {
namespace Droid {
namespace SystemUI {
namespace StatusBar {
namespace Policy {

const String KeyguardUserSwitcher::TAG("KeyguardUserSwitcher");
const Boolean KeyguardUserSwitcher::ALWAYS_ON = FALSE;

CAR_INTERFACE_IMPL(KeyguardUserSwitcher::Adapter, BaseUserAdapter, IViewOnClickListener)

KeyguardUserSwitcher::Adapter::Adapter(
    /* [in] */ IContext* context,
    /* [in] */ IUserSwitcherController* controller,
    /* [in] */ KeyguardUserSwitcher* host)
    : BaseUserAdapter((UserSwitcherController*)controller)
    , mHost(host)
{
    mContext = context;
}

ECode KeyguardUserSwitcher::Adapter::GetView(
    /* [in] */ Int32 position,
    /* [in] */ IView* _convertView,
    /* [in] */ IViewGroup* parent,
    /* [out] */ IView** view)
{
    VALIDATE_NOT_NULL(view);
    AutoPtr<IInterface> obj;
    GetItem(position, (IInterface**)&obj);
    AutoPtr<IUserSwitcherControllerUserRecord> i = IUserSwitcherControllerUserRecord::Probe(obj);
    UserSwitcherController::UserRecord* item = (UserSwitcherController::UserRecord*)i.Get();

    AutoPtr<IView> convertView = _convertView;
    AutoPtr<IInterface> tag;
    convertView->GetTag((IInterface**)&tag);
    if (IUserDetailItemView::Probe(convertView) == NULL
            || IUserSwitcherControllerUserRecord::Probe(tag) == NULL) {
        AutoPtr<ILayoutInflater> flater;
        LayoutInflater::From(mContext, (ILayoutInflater**)&flater);
        flater->Inflate(
                R::layout::keyguard_user_switcher_item, parent, FALSE, (IView**)&convertView);
        convertView->SetOnClickListener(this);
    }
    AutoPtr<IUserDetailItemView> v = IUserDetailItemView::Probe(convertView);

    String name;
    GetName(mContext, i, &name);
    if (item->mPicture == NULL) {
        AutoPtr<IDrawable> d;
        GetDrawable(mContext, i, (IDrawable**)&d);
        v->Bind(name, d);
    }
    else {
        v->Bind(name, item->mPicture);
    }
    convertView->SetActivated(item->mIsCurrent);
    convertView->SetTag(i);
    *view = convertView;
    REFCOUNT_ADD(*view);
    return NOERROR;
}

ECode KeyguardUserSwitcher::Adapter::OnClick(
    /* [in] */ IView* v)
{
    AutoPtr<IInterface> tag;
    v->GetTag((IInterface**)&tag);
    AutoPtr<IUserSwitcherControllerUserRecord> r;
    SwitchTo(IUserSwitcherControllerUserRecord::Probe(tag));
    return NOERROR;
}

KeyguardUserSwitcher::_DataSetObserver::_DataSetObserver(
    /* [in] */ KeyguardUserSwitcher* host)
    : mHost(host)
{}

ECode KeyguardUserSwitcher::_DataSetObserver::OnChanged()
{
    mHost->Refresh();
    return NOERROR;
}

KeyguardUserSwitcher::BgAnimatorListenerAdapter::BgAnimatorListenerAdapter(
    /* [in] */ KeyguardUserSwitcher* host)
    : mHost(host)
{}

ECode KeyguardUserSwitcher::BgAnimatorListenerAdapter::OnAnimationEnd(
    /* [in] */ IAnimator* animator)
{
    mHost->mBgAnimator = NULL;
    return NOERROR;
}

KeyguardUserSwitcher::DisappearAnimationRunnable::DisappearAnimationRunnable(
    /* [in] */ KeyguardUserSwitcher* host)
    : mHost(host)
{}

ECode KeyguardUserSwitcher::DisappearAnimationRunnable::Run()
{
    IView::Probe(mHost->mUserSwitcher)->SetVisibility(IView::GONE);
    IView::Probe(mHost->mUserSwitcher)->SetAlpha(1.f);
    return NOERROR;
}

KeyguardUserSwitcher::AppearAnimationRunnable::AppearAnimationRunnable(
    /* [in] */ KeyguardUserSwitcher* host)
    : mHost(host)
{}


ECode KeyguardUserSwitcher::AppearAnimationRunnable::Run()
{
    IViewGroup::Probe(mHost->mUserSwitcher)->SetClipChildren(TRUE);
    IViewGroup::Probe(mHost->mUserSwitcher)->SetClipToPadding(TRUE);
    return NOERROR;
}

CAR_INTERFACE_IMPL(KeyguardUserSwitcher, Object, IKeyguardUserSwitcher)
KeyguardUserSwitcher::KeyguardUserSwitcher(
    /* [in] */ IContext* context,
    /* [in] */ IViewStub* userSwitcher,
    /* [in] */ IKeyguardStatusBarView* statusBarView,
    /* [in] */ INotificationPanelView* panelView,
    /* [in] */ IUserSwitcherController* userSwitcherController)
{
    AutoPtr<IResources> res;
    context->GetResources((IResources**)&res);
    Boolean tmp = FALSE;
    res->GetBoolean(R::bool_::config_keyguardUserSwitcher, &tmp);
    if (tmp || ALWAYS_ON) {
        AutoPtr<IView> view;
        userSwitcher->Inflate((IView**)&view);
        mUserSwitcher = IViewGroup::Probe(view);
        CKeyguardUserSwitcherScrim::New(IView::Probe(mUserSwitcher), (IKeyguardUserSwitcherScrim**)&mBackground);
        IView::Probe(mUserSwitcher)->SetBackground(IDrawable::Probe(mBackground));
        mStatusBarView = statusBarView;
        mStatusBarView->SetKeyguardUserSwitcher(this);
        panelView->SetKeyguardUserSwitcher(this);
        mAdapter = new Adapter(context, userSwitcherController, this);
        mAdapter->RegisterDataSetObserver(mDataSetObserver);
        mUserSwitcherController = userSwitcherController;

        AutoPtr<IInterpolator> interpolator;
        AnimationUtils::LoadInterpolator(context,
            Elastos::Droid::R::interpolator::fast_out_slow_in, (IInterpolator**)&interpolator);
        mAppearAnimationUtils = new AppearAnimationUtils();
        mAppearAnimationUtils->constructor(context, 400, -0.5f, 0.5f, interpolator);
    }
    else {
        mUserSwitcher = NULL;
        mStatusBarView = NULL;
        mAdapter = NULL;
        mAppearAnimationUtils = NULL;
        mBackground = NULL;
    }
}

ECode KeyguardUserSwitcher::SetKeyguard(
    /* [in] */ Boolean keyguard,
    /* [in] */ Boolean animate)
{
    if (mUserSwitcher != NULL) {
        if (keyguard && ShouldExpandByDefault()) {
            Show(animate);
        }
        else {
            Hide(animate);
        }
    }
    return NOERROR;
}

Boolean KeyguardUserSwitcher::ShouldExpandByDefault()
{
    Boolean tmp = FALSE;
    return (mUserSwitcherController != NULL) && (mUserSwitcherController->IsSimpleUserSwitcher(&tmp), tmp);
}

ECode KeyguardUserSwitcher::Show(
    /* [in] */ Boolean animate)
{
    Int32 v = 0;
    if (mUserSwitcher != NULL && (IView::Probe(mUserSwitcher)->GetVisibility(&v), v) != IView::VISIBLE) {
        CancelAnimations();
        IView::Probe(mUserSwitcher)->SetVisibility(IView::VISIBLE);
        mStatusBarView->SetKeyguardUserSwitcherShowing(TRUE, animate);
        if (animate) {
            StartAppearAnimation();
        }
    }
    return NOERROR;
}

ECode KeyguardUserSwitcher::Hide(
    /* [in] */ Boolean animate)
{
    Int32 v = 0;
    if (mUserSwitcher != NULL && (IView::Probe(mUserSwitcher)->GetVisibility(&v), v) == IView::VISIBLE) {
        CancelAnimations();
        if (animate) {
            StartDisappearAnimation();
        }
        else {
            IView::Probe(mUserSwitcher)->SetVisibility(IView::GONE);
        }
        mStatusBarView->SetKeyguardUserSwitcherShowing(FALSE, animate);
    }
    return NOERROR;
}

void KeyguardUserSwitcher::CancelAnimations()
{
    Int32 count = 0;
    mUserSwitcher->GetChildCount(&count);
    for (Int32 i = 0; i < count; i++) {
        AutoPtr<IView> child;
        mUserSwitcher->GetChildAt(i, (IView**)&child);
        AutoPtr<IViewPropertyAnimator> vp;
        child->Animate((IViewPropertyAnimator**)&vp);
        vp->Cancel();
    }
    if (mBgAnimator != NULL) {
        IAnimator::Probe(mBgAnimator)->Cancel();
    }

    AutoPtr<IViewPropertyAnimator> vp;
    IView::Probe(mUserSwitcher)->Animate((IViewPropertyAnimator**)&vp);
    vp->Cancel();
}

void KeyguardUserSwitcher::StartAppearAnimation()
{
    Int32 count = 0;
    mUserSwitcher->GetChildCount(&count);
    AutoPtr<ArrayOf<IInterface*> > objects = ArrayOf<IInterface*>::Alloc(count);
    for (Int32 i = 0; i < count; i++) {
        AutoPtr<IView> view;
        mUserSwitcher->GetChildAt(i, (IView**)&view);
        objects->Set(i, view);
    }
    mUserSwitcher->SetClipChildren(FALSE);
    mUserSwitcher->SetClipToPadding(FALSE);

    AutoPtr<IRunnable> runnable = new AppearAnimationRunnable(this);
    mAppearAnimationUtils->StartAppearAnimation(objects, runnable);

    AutoPtr<IObjectAnimatorHelper> helper;
    CObjectAnimatorHelper::AcquireSingleton((IObjectAnimatorHelper**)&helper);

    AutoPtr<ArrayOf<Int32> > ivs = ArrayOf<Int32>::Alloc(2);
    (*ivs)[0] = 0;
    (*ivs)[1] = 255;
    helper->OfInt32(mBackground, String("alpha"), ivs, (IObjectAnimator**)&mBgAnimator);
    IValueAnimator::Probe(mBgAnimator)->SetDuration(400);
    IAnimator* animator = IAnimator::Probe(mBgAnimator);
    animator->SetInterpolator(ITimeInterpolator::Probe(CPhoneStatusBar::ALPHA_IN));
    AutoPtr<BgAnimatorListenerAdapter> listener = new BgAnimatorListenerAdapter(this);
    animator->AddListener(listener);
    animator->Start();
}

void KeyguardUserSwitcher::StartDisappearAnimation()
{
    AutoPtr<IViewPropertyAnimator> vp;
    IView::Probe(mUserSwitcher)->Animate((IViewPropertyAnimator**)&vp);
    vp->Alpha(0.f);
    vp->SetDuration(300);
    vp->SetInterpolator(ITimeInterpolator::Probe(CPhoneStatusBar::ALPHA_OUT));
    AutoPtr<DisappearAnimationRunnable> run = new DisappearAnimationRunnable(this);
    vp->WithEndAction(run);
}

void KeyguardUserSwitcher::Refresh()
{
    Int32 childCount = 0;
    mUserSwitcher->GetChildCount(&childCount);
    Int32 adapterCount = 0;
    mAdapter->GetCount(&adapterCount);
    const Int32 N = Elastos::Core::Math::Max(childCount, adapterCount);
    for (Int32 i = 0; i < N; i++) {
        if (i < adapterCount) {
            AutoPtr<IView> oldView;
            if (i < childCount) {
                mUserSwitcher->GetChildAt(i, (IView**)&oldView);
            }
            AutoPtr<IView> newView;
            mAdapter->GetView(i, oldView, mUserSwitcher, (IView**)&newView);
            if (oldView == NULL) {
                // We ran out of existing views. Add it at the end.
                mUserSwitcher->AddView(newView);
            }
            else if (oldView != newView) {
                // We couldn't rebind the view. Replace it.
                mUserSwitcher->RemoveViewAt(i);
                mUserSwitcher->AddView(newView, i);
            }
        }
        else {
            Int32 tmp = 0;
            mUserSwitcher->GetChildCount(&tmp);
            Int32 lastIndex = tmp - 1;
            mUserSwitcher->RemoveViewAt(lastIndex);
        }
    }
}

} // namespace Policy
} // namespace StatusBar
} // namespace SystemUI
} // namespace Droid
} // namespace Elastos
