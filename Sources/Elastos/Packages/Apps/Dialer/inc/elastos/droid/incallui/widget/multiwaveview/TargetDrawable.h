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

#ifndef __ELASTOS_DROID_INCALLUI_WIDGET_MULTIWAVEVIEW_TARGETDRAWABLE_H__
#define __ELASTOS_DROID_INCALLUI_WIDGET_MULTIWAVEVIEW_TARGETDRAWABLE_H__

#include "Elastos.Droid.Content.h"
#include "Elastos.Droid.Graphics.h"
#include "_Elastos.Droid.Dialer.h"
#include <elastos/core/Object.h>

using Elastos::Droid::Content::Res::IResources;
using Elastos::Droid::Graphics::ICanvas;
using Elastos::Droid::Graphics::Drawable::IDrawable;
using Elastos::Core::Object;

namespace Elastos {
namespace Droid {
namespace InCallUI {
namespace Widget {
namespace MultiwaveView {

class TargetDrawable
    : public Object
    , public ITargetDrawable
{
public:
    CAR_INTERFACE_DECL();

    TargetDrawable();

    /**
     * This is changed from the framework version to pass in the number of drawables in the
     * container. The framework version relies on private api's to get the count from
     * StateListDrawable.
     *
     * @param res
     * @param resId
     * @param count The number of drawables in the resource.
     */
    CARAPI constructor(
        /* [in] */ IResources* res,
        /* [in] */ Int32 resId,
        /* [in] */ Int32 count);

    CARAPI constructor(
        /* [in] */ ITargetDrawable* other);

    CARAPI_(void) SetDrawable(
        /* [in] */ IResources* res,
        /* [in] */ Int32 resId);

    CARAPI_(void) SetState(
        /* [in] */ ArrayOf<Int32>* state);

    /**
     * Returns true if the drawable is a StateListDrawable and is in the focused state.
     *
     * @return
     */
    CARAPI_(Boolean) IsActive();

    /**
     * Returns true if this target is enabled. Typically an enabled target contains a valid
     * drawable in a valid state. Currently all targets with valid drawables are valid.
     *
     * @return
     */
    CARAPI_(Boolean) IsEnabled();

    CARAPI_(void) SetX(
        /* [in] */ Float x);

    CARAPI_(void) SetY(
        /* [in] */ Float y);

    CARAPI SetScaleX(
        /* [in] */ Float x);

    CARAPI SetScaleY(
        /* [in] */ Float y);

    CARAPI SetAlpha(
        /* [in] */ Float alpha);

    CARAPI_(Float) GetX();

    CARAPI_(Float) GetY();

    CARAPI_(Float) GetScaleX();

    CARAPI_(Float) GetScaleY();

    CARAPI_(Float) GetAlpha();

    CARAPI_(void) SetPositionX(
        /* [in] */ Float x);

    CARAPI_(void) SetPositionY(
        /* [in] */ Float y);

    CARAPI_(Float) GetPositionX();

    CARAPI_(Float) GetPositionY();

    CARAPI_(Int32) GetWidth();

    CARAPI_(Int32) GetHeight();

    CARAPI_(void) Draw(
        /* [in] */ ICanvas* canvas);

    CARAPI_(void) SetEnabled(
        /* [in] */ Boolean enabled);

    CARAPI_(Int32) GetResourceId();

private:
    /**
     * Makes drawables in a StateListDrawable all the same dimensions.
     * If not a StateListDrawable, then justs sets the bounds to the intrinsic size of the
     * drawable.
     */
    CARAPI_(void) ResizeDrawables();

public:
    static AutoPtr<ArrayOf<Int32> > STATE_ACTIVE;
    static AutoPtr<ArrayOf<Int32> > STATE_INACTIVE;
    static AutoPtr<ArrayOf<Int32> > STATE_FOCUSED;

private:
    static const String TAG;
    static const Boolean DEBUG;
    Float mTranslationX;
    Float mTranslationY;
    Float mPositionX;
    Float mPositionY;
    Float mScaleX;
    Float mScaleY;
    Float mAlpha;
    AutoPtr<IDrawable> mDrawable;
    Boolean mEnabled;
    Int32 mResourceId;
    Int32 mNumDrawables;
};

} // namespace MultiwaveView
} // namespace Widget
} // namespace InCallUI
} // namespace Droid
} // namespace Elastos

#endif // __ELASTOS_DROID_INCALLUI_WIDGET_MULTIWAVEVIEW_TARGETDRAWABLE_H__
