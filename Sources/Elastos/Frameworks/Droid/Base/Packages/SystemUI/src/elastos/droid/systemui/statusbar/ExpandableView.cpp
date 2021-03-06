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

#include "elastos/droid/systemui/statusbar/ExpandableView.h"
#include "R.h"
#include <elastos/core/Math.h>

using Elastos::Utility::CArrayList;
using Elastos::Utility::IIterator;

namespace Elastos {
namespace Droid {
namespace SystemUI {
namespace StatusBar {

CAR_INTERFACE_IMPL(ExpandableView, FrameLayout, IExpandableView)
ExpandableView::ExpandableView()
    : mActualHeight(0)
    , mClipTopAmount(0)
    , mMaxNotificationHeight(0)
    , mActualHeightInitialized(0)
{
    CArrayList::New((IArrayList**)&mMatchParentViews);
}

ECode ExpandableView::constructor(
    /* [in] */ IContext* context,
    /* [in] */ IAttributeSet* attrs)
{
    FrameLayout::constructor(context, attrs);
    AutoPtr<IResources> res;
    GetResources((IResources**)&res);
    res->GetDimensionPixelSize(R::dimen::notification_max_height, &mMaxNotificationHeight);
    return NOERROR;
}

ECode ExpandableView::OnMeasure(
    /* [in] */ Int32 widthMeasureSpec,
    /* [in] */ Int32 heightMeasureSpec)
{
    Int32 ownMaxHeight = mMaxNotificationHeight;
    Int32 heightMode = MeasureSpec::GetMode(heightMeasureSpec);
    Boolean hasFixedHeight = heightMode == MeasureSpec::EXACTLY;
    Boolean isHeightLimited = heightMode == MeasureSpec::AT_MOST;
    if (hasFixedHeight || isHeightLimited) {
        Int32 size = MeasureSpec::GetSize(heightMeasureSpec);
        ownMaxHeight = Elastos::Core::Math::Min(ownMaxHeight, size);
    }
    Int32 newHeightSpec = MeasureSpec::MakeMeasureSpec(ownMaxHeight, MeasureSpec::AT_MOST);
    Int32 maxChildHeight = 0;
    Int32 childCount = 0;
    GetChildCount(&childCount);
    for (Int32 i = 0; i < childCount; i++) {
        AutoPtr<IView> child;
        GetChildAt(i, (IView**)&child);
        Int32 childHeightSpec = newHeightSpec;
        AutoPtr<IViewGroupLayoutParams> layoutParams;
        child->GetLayoutParams((IViewGroupLayoutParams**)&layoutParams);
        Int32 height = 0;
        layoutParams->GetHeight(&height);
        if (height != IViewGroupLayoutParams::MATCH_PARENT) {
            if (height >= 0) {
                // An actual height is set
                childHeightSpec = height > ownMaxHeight
                    ? MeasureSpec::MakeMeasureSpec(ownMaxHeight, MeasureSpec::EXACTLY)
                    : MeasureSpec::MakeMeasureSpec(height, MeasureSpec::EXACTLY);
            }
            Int32 width = 0;
            layoutParams->GetWidth(&width);
            child->Measure(GetChildMeasureSpec(widthMeasureSpec, 0 /* padding */, width), childHeightSpec);
            Int32 childHeight = 0;
            child->GetMeasuredHeight(&childHeight);
            maxChildHeight = Elastos::Core::Math::Max(maxChildHeight, childHeight);
        }
        else {
            mMatchParentViews->Add(child);
        }
    }
    Int32 ownHeight = hasFixedHeight ? ownMaxHeight : maxChildHeight;
    newHeightSpec = MeasureSpec::MakeMeasureSpec(ownHeight, MeasureSpec::EXACTLY);

    AutoPtr<IIterator> ator;
    mMatchParentViews->GetIterator((IIterator**)&ator);
    Boolean hasNext = FALSE;
    while (ator->HasNext(&hasNext), hasNext) {
        AutoPtr<IInterface> obj;
        ator->GetNext((IInterface**)&obj);
        AutoPtr<IView> child = IView::Probe(obj);

        AutoPtr<IViewGroupLayoutParams> layoutParams;
        child->GetLayoutParams((IViewGroupLayoutParams**)&layoutParams);
        Int32 width = 0;
        layoutParams->GetWidth(&width);
        child->Measure(GetChildMeasureSpec(widthMeasureSpec, 0 /* padding */, width), newHeightSpec);
    }
    mMatchParentViews->Clear();
    Int32 width = MeasureSpec::GetSize(widthMeasureSpec);
    SetMeasuredDimension(width, ownHeight);
    return NOERROR;
}

ECode ExpandableView::OnLayout(
    /* [in] */ Boolean changed,
    /* [in] */ Int32 left,
    /* [in] */ Int32 top,
    /* [in] */ Int32 right,
    /* [in] */ Int32 bottom)
{
    FrameLayout::OnLayout(changed, left, top, right, bottom);
    if (!mActualHeightInitialized && mActualHeight == 0) {
        Int32 initialHeight = GetInitialHeight();
        if (initialHeight != 0) {
            SetActualHeight(initialHeight);
        }
    }
    return NOERROR;
}

Int32 ExpandableView::GetInitialHeight()
{
    Int32 height = 0;
    GetHeight(&height);
    return height;
}

ECode ExpandableView::DispatchTouchEvent(
    /* [in] */ IMotionEvent* ev,
    /* [out] */ Boolean* result)
{
    VALIDATE_NOT_NULL(result);
    if (FilterMotionEvent(ev)) {
        return FrameLayout::DispatchTouchEvent(ev, result);
    }
    *result = FALSE;
    return NOERROR;
}

Boolean ExpandableView::FilterMotionEvent(
    /* [in] */ IMotionEvent* event)
{
    Int32 masked = 0;
    event->GetActionMasked(&masked);
    Float y = 0;
    return masked != IMotionEvent::ACTION_DOWN
            || ((event->GetY(&y), y) > mClipTopAmount && y < mActualHeight);
}

ECode ExpandableView::SetActualHeight(
    /* [in] */ Int32 actualHeight,
    /* [in] */ Boolean notifyListeners)
{
    mActualHeightInitialized = TRUE;
    mActualHeight = actualHeight;
    if (notifyListeners) {
        NotifyHeightChanged();
    }
    return NOERROR;
}

ECode ExpandableView::SetActualHeight(
    /* [in] */ Int32 actualHeight)
{
    return SetActualHeight(actualHeight, TRUE);
}

ECode ExpandableView::GetActualHeight(
    /* [out] */ Int32* height)
{
    VALIDATE_NOT_NULL(height);
    *height = mActualHeight;
    return NOERROR;
}

ECode ExpandableView::GetMaxHeight(
    /* [out] */ Int32* height)
{
    VALIDATE_NOT_NULL(height);
    return GetHeight(height);
}

ECode ExpandableView::GetMinHeight(
    /* [out] */ Int32* height)
{
    VALIDATE_NOT_NULL(height);
    return GetHeight(height);
}

ECode ExpandableView::SetDimmed(
    /* [in] */ Boolean dimmed,
    /* [in] */ Boolean fade)
{
    return NOERROR;
}

ECode ExpandableView::SetDark(
    /* [in] */ Boolean dark,
    /* [in] */ Boolean fade)
{
    return NOERROR;
}

ECode ExpandableView::SetHideSensitiveForIntrinsicHeight(
    /* [in] */ Boolean hideSensitive)
{
    return NOERROR;
}

ECode ExpandableView::SetHideSensitive(
    /* [in] */ Boolean hideSensitive,
    /* [in] */ Boolean animated,
    /* [in] */ Int64 delay,
    /* [in] */ Int64 duration)
{
    return NOERROR;
}

ECode ExpandableView::GetIntrinsicHeight(
    /* [out] */ Int32* height)
{
    VALIDATE_NOT_NULL(height);
    return GetHeight(height);
}

ECode ExpandableView::SetClipTopAmount(
    /* [in] */ Int32 clipTopAmount)
{
    mClipTopAmount = clipTopAmount;
    return NOERROR;
}

ECode ExpandableView::GetClipTopAmount(
    /* [out] */ Int32* amount)
{
    VALIDATE_NOT_NULL(amount);
    *amount = mClipTopAmount;
    return NOERROR;
}

ECode ExpandableView::SetOnHeightChangedListener(
    /* [in] */ IExpandableViewOnHeightChangedListener* listener)
{
    mOnHeightChangedListener = listener;
    return NOERROR;
}

ECode ExpandableView::IsContentExpandable(
    /* [out] */ Boolean* result)
{
    VALIDATE_NOT_NULL(result);
    *result = FALSE;
    return NOERROR;
}

ECode ExpandableView::NotifyHeightChanged()
{
    if (mOnHeightChangedListener != NULL) {
        mOnHeightChangedListener->OnHeightChanged(this);
    }
    return NOERROR;
}

ECode ExpandableView::IsTransparent(
    /* [out] */ Boolean* result)
{
    VALIDATE_NOT_NULL(result);
    *result = FALSE;
    return NOERROR;
}

ECode ExpandableView::SetBelowSpeedBump(
    /* [in] */ Boolean below)
{
    return NOERROR;
}

ECode ExpandableView::OnHeightReset()
{
    if (mOnHeightChangedListener != NULL) {
        mOnHeightChangedListener->OnReset(this);
    }
    return NOERROR;
}

ECode ExpandableView::GetDrawingRect(
    /* [in] */ IRect* outRect)
{
    FrameLayout::GetDrawingRect(outRect);
    Int32 left = 0, top = 0, right = 0, bottom = 0;
    outRect->Get(&left, &top, &right, &bottom);

    Float x = 0, y = 0;
    GetTranslationX(&x);
    GetTranslationY(&y);
    Int32 height = 0, amount = 0;
    GetActualHeight(&height);
    GetClipTopAmount(&amount);
    outRect->Set(left + x, top + y + amount, right + x, top + y + height);
    return NOERROR;
}

} // namespace StatusBar
} // namespace SystemUI
} // namespace Droid
} // namespace Elastos
