
#ifndef __ELASTOS_DROID_VIEW_ANIMATION_ROTATEANIMATION_H__
#define __ELASTOS_DROID_VIEW_ANIMATION_ROTATEANIMATION_H__

#include "elastos/droid/view/animation/Animation.h"

namespace Elastos {
namespace Droid {
namespace View {
namespace Animation {

class RotateAnimation
    : public Animation
    , public IRotateAnimation
{
public:
    CAR_INTERFACE_DECL();

    RotateAnimation();

    CARAPI constructor(
        /* [in] */ IContext* context,
        /* [in] */ IAttributeSet* attrs);

    CARAPI constructor(
        /* [in] */ Float fromDegrees,
        /* [in] */ Float toDegrees);

    CARAPI constructor(
        /* [in] */ Float fromDegrees,
        /* [in] */ Float toDegrees,
        /* [in] */ Float pivotX,
        /* [in] */ Float pivotY);

    CARAPI constructor(
        /* [in] */ Float fromDegrees,
        /* [in] */ Float toDegrees,
        /* [in] */ Int32 pivotXType,
        /* [in] */ Float pivotXValue,
        /* [in] */ Int32 pivotYType,
        /* [in] */ Float pivotYValue);

    //@Override
    CARAPI Initialize(
        /* [in] */ Int32 width,
        /* [in] */ Int32 height,
        /* [in] */ Int32 parentWidth,
        /* [in] */ Int32 parentHeight);

protected:
    //@Override
    CARAPI_(void) ApplyTransformation(
        /* [in] */ Float interpolatedTime,
        /* [in] */ ITransformation* t);

    // @Override
    CARAPI Clone(
        /* [out] */ IInterface** object);

    CARAPI CloneImpl(
        /* [in] */ IRotateAnimation* object);

private:
    /**
     * Called at the end of constructor methods to initialize, if possible, values for
     * the pivot point. This is only possible for ABSOLUTE pivot values.
     */
    CARAPI_(void) InitializePivotPoint();

private:
    Float mFromDegrees;
    Float mToDegrees;

    Int32 mPivotXType;
    Int32 mPivotYType;
    Float mPivotXValue;
    Float mPivotYValue;

    Float mPivotX;
    Float mPivotY;
};

}   //namespace Animation
}   //namespace View
}   //namespace Droid
}   //namespace Elastos
#endif //__ELASTOS_DROID_VIEW_ANIMATION_ROTATEANIMATION_H__
