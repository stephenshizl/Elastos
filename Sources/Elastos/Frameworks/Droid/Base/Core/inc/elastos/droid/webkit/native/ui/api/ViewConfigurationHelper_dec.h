//This file is autogenerated for
//    ViewConfigurationHelper.java
//put this file at the end of the include list
//so the type definition used in this file will be found
#ifndef ELASTOS_VIEWCONFIGURATIONHELPER_CALLBACK_DEC_HH
#define ELASTOS_VIEWCONFIGURATIONHELPER_CALLBACK_DEC_HH


#ifdef __cplusplus
extern "C"
{
#endif
    extern void Elastos_ViewConfigurationHelper_nativeUpdateSharedViewConfiguration(IInterface* caller,Int32 scaledMaximumFlingVelocity,Int32 scaledMinimumFlingVelocity,Int32 scaledTouchSlop,Int32 scaledDoubleTapSlop,Int32 scaledMinScalingSpan,Int32 scaledMinScalingTouchMajor);
    extern void Elastos_ViewConfigurationHelper_InitCallback(Handle32 cb);
#ifdef __cplusplus
}
#endif


namespace Elastos {
namespace Droid {
namespace Webkit {
namespace Ui {
namespace Gfx {

struct ElaViewConfigurationHelperCallback
{
    Int32 (*elastos_ViewConfigurationHelper_getDoubleTapTimeout)();
    Int32 (*elastos_ViewConfigurationHelper_getLongPressTimeout)();
    Int32 (*elastos_ViewConfigurationHelper_getTapTimeout)();
    Float (*elastos_ViewConfigurationHelper_getScrollFriction)();
    Int32 (*elastos_ViewConfigurationHelper_getScaledMaximumFlingVelocity)(IInterface* obj);
    Int32 (*elastos_ViewConfigurationHelper_getScaledMinimumFlingVelocity)(IInterface* obj);
    Int32 (*elastos_ViewConfigurationHelper_getScaledTouchSlop)(IInterface* obj);
    Int32 (*elastos_ViewConfigurationHelper_getScaledDoubleTapSlop)(IInterface* obj);
    Int32 (*elastos_ViewConfigurationHelper_getScaledMinScalingSpan)(IInterface* obj);
    Int32 (*elastos_ViewConfigurationHelper_getScaledMinScalingTouchMajor)(IInterface* obj);
    AutoPtr<IInterface> (*elastos_ViewConfigurationHelper_createWithListener)(IInterface* context);
};

void* ViewConfigurationHelper::ElaViewConfigurationHelperCallback_Init()
{
    static ElaViewConfigurationHelperCallback sElaViewConfigurationHelperCallback;

    sElaViewConfigurationHelperCallback.elastos_ViewConfigurationHelper_getDoubleTapTimeout = &ViewConfigurationHelper::GetDoubleTapTimeout;
    sElaViewConfigurationHelperCallback.elastos_ViewConfigurationHelper_getLongPressTimeout = &ViewConfigurationHelper::GetLongPressTimeout;
    sElaViewConfigurationHelperCallback.elastos_ViewConfigurationHelper_getTapTimeout = &ViewConfigurationHelper::GetTapTimeout;
    sElaViewConfigurationHelperCallback.elastos_ViewConfigurationHelper_getScrollFriction = &ViewConfigurationHelper::GetScrollFriction;
    sElaViewConfigurationHelperCallback.elastos_ViewConfigurationHelper_getScaledMaximumFlingVelocity = &ViewConfigurationHelper::GetScaledMaximumFlingVelocity;
    sElaViewConfigurationHelperCallback.elastos_ViewConfigurationHelper_getScaledMinimumFlingVelocity = &ViewConfigurationHelper::GetScaledMinimumFlingVelocity;
    sElaViewConfigurationHelperCallback.elastos_ViewConfigurationHelper_getScaledTouchSlop = &ViewConfigurationHelper::GetScaledTouchSlop;
    sElaViewConfigurationHelperCallback.elastos_ViewConfigurationHelper_getScaledDoubleTapSlop = &ViewConfigurationHelper::GetScaledDoubleTapSlop;
    sElaViewConfigurationHelperCallback.elastos_ViewConfigurationHelper_getScaledMinScalingSpan = &ViewConfigurationHelper::GetScaledMinScalingSpan;
    sElaViewConfigurationHelperCallback.elastos_ViewConfigurationHelper_getScaledMinScalingTouchMajor = &ViewConfigurationHelper::GetScaledMinScalingTouchMajor;
    sElaViewConfigurationHelperCallback.elastos_ViewConfigurationHelper_createWithListener = &ViewConfigurationHelper::CreateWithListener;

    Elastos_ViewConfigurationHelper_InitCallback((Handle32)&sElaViewConfigurationHelperCallback);
    return &sElaViewConfigurationHelperCallback;
}

static void* sPElaViewConfigurationHelperCallback = ViewConfigurationHelper::ElaViewConfigurationHelperCallback_Init();

} // namespace Gfx
} // namespace Ui
} // namespace Webkit
} // namespace Droid
} // namespace Elastos

#endif //ELASTOS_VIEWCONFIGURATIONHELPER_CALLBACK_DEC_HH
