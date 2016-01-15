//This file is autogenerated for
//    ContentVideoView.java
//put this file at the end of the include list
//so the type definition used in this file will be found
#ifndef ELASTOS_CONTENTVIDEOVIEW_CALLBACK_DEC_HH
#define ELASTOS_CONTENTVIDEOVIEW_CALLBACK_DEC_HH


#ifdef __cplusplus
extern "C"
{
#endif
    extern AutoPtr<IInterface> Elastos_ContentVideoView_nativeGetSingletonJavaContentVideoView();
    extern void Elastos_ContentVideoView_nativeExitFullscreen(IInterface* caller,Handle32 nativeContentVideoView,Boolean relaseMediaPlayer);
    extern Int32 Elastos_ContentVideoView_nativeGetCurrentPosition(IInterface* caller,Handle32 nativeContentVideoView);
    extern Int32 Elastos_ContentVideoView_nativeGetDurationInMilliSeconds(IInterface* caller,Handle32 nativeContentVideoView);
    extern void Elastos_ContentVideoView_nativeRequestMediaMetadata(IInterface* caller,Handle32 nativeContentVideoView);
    extern Int32 Elastos_ContentVideoView_nativeGetVideoWidth(IInterface* caller,Handle32 nativeContentVideoView);
    extern Int32 Elastos_ContentVideoView_nativeGetVideoHeight(IInterface* caller,Handle32 nativeContentVideoView);
    extern Boolean Elastos_ContentVideoView_nativeIsPlaying(IInterface* caller,Handle32 nativeContentVideoView);
    extern void Elastos_ContentVideoView_nativePause(IInterface* caller,Handle32 nativeContentVideoView);
    extern void Elastos_ContentVideoView_nativePlay(IInterface* caller,Handle32 nativeContentVideoView);
    extern void Elastos_ContentVideoView_nativeSeekTo(IInterface* caller,Handle32 nativeContentVideoView,Int32 msec);
    extern void Elastos_ContentVideoView_nativeSetSurface(IInterface* caller,Handle32 nativeContentVideoView,IInterface* surface);
    extern void Elastos_ContentVideoView_InitCallback(Handle32 cb);
#ifdef __cplusplus
}
#endif


namespace Elastos {
namespace Droid {
namespace Webkit {
namespace Content {
namespace Browser {

struct ElaContentVideoViewCallback
{
    void (*elastos_ContentVideoView_onMediaPlayerError)(IInterface* obj, Int32 errorType);
    void (*elastos_ContentVideoView_onVideoSizeChanged)(IInterface* obj, Int32 width, Int32 height);
    void (*elastos_ContentVideoView_onBufferingUpdate)(IInterface* obj, Int32 percent);
    void (*elastos_ContentVideoView_onPlaybackComplete)(IInterface* obj);
    void (*elastos_ContentVideoView_onUpdateMediaMetadata)(IInterface* obj, Int32 videoWidth, Int32 videoHeight, Int32 duration, Boolean canPause, Boolean canSeekBack, Boolean canSeekForward);
    void (*elastos_ContentVideoView_openVideo)(IInterface* obj);
    AutoPtr<IInterface> (*elastos_ContentVideoView_createContentVideoView)(IInterface* context, Int64 nativeContentVideoView, IInterface* client, Boolean legacy);
    void (*elastos_ContentVideoView_onExitFullscreen)(IInterface* obj);
    void (*elastos_ContentVideoView_destroyContentVideoView)(IInterface* obj, Boolean nativeViewDestroyed);
    Int64 (*elastos_ContentVideoView_getNativeViewAndroid)(IInterface* obj);
};

void* ContentVideoView::ElaContentVideoViewCallback_Init()
{
    static ElaContentVideoViewCallback sElaContentVideoViewCallback;

    sElaContentVideoViewCallback.elastos_ContentVideoView_onMediaPlayerError = &ContentVideoView::OnMediaPlayerError;
    sElaContentVideoViewCallback.elastos_ContentVideoView_onVideoSizeChanged = &ContentVideoView::OnVideoSizeChanged;
    sElaContentVideoViewCallback.elastos_ContentVideoView_onBufferingUpdate = &ContentVideoView::OnBufferingUpdate;
    sElaContentVideoViewCallback.elastos_ContentVideoView_onPlaybackComplete = &ContentVideoView::OnPlaybackComplete;
    sElaContentVideoViewCallback.elastos_ContentVideoView_onUpdateMediaMetadata = &ContentVideoView::OnUpdateMediaMetadata;
    sElaContentVideoViewCallback.elastos_ContentVideoView_openVideo = &ContentVideoView::OpenVideo;
    sElaContentVideoViewCallback.elastos_ContentVideoView_createContentVideoView = &ContentVideoView::CreateContentVideoView;
    sElaContentVideoViewCallback.elastos_ContentVideoView_onExitFullscreen = &ContentVideoView::OnExitFullscreen;
    sElaContentVideoViewCallback.elastos_ContentVideoView_destroyContentVideoView = &ContentVideoView::DestroyContentVideoView;
    sElaContentVideoViewCallback.elastos_ContentVideoView_getNativeViewAndroid = &ContentVideoView::GetNativeViewAndroid;

    Elastos_ContentVideoView_InitCallback((Handle32)&sElaContentVideoViewCallback);
    return &sElaContentVideoViewCallback;
}

static void* sPElaContentVideoViewCallback = ContentVideoView::ElaContentVideoViewCallback_Init();

} // namespace Browser
} // namespace Content
} // namespace Webkit
} // namespace Droid
} // namespace Elastos

#endif //ELASTOS_CONTENTVIDEOVIEW_CALLBACK_DEC_HH
