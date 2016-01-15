//This file is autogenerated for
//    WebContentsDelegateAndroid.java
//put this file at the end of the include list
//so the type definition used in this file will be found
#ifndef ELASTOS_WEBCONTENTSDELEGATEANDROID_CALLBACK_DEC_HH
#define ELASTOS_WEBCONTENTSDELEGATEANDROID_CALLBACK_DEC_HH


#ifdef __cplusplus
extern "C"
{
#endif
    extern void Elastos_WebContentsDelegateAndroid_InitCallback(Handle32 cb);
#ifdef __cplusplus
}
#endif

namespace Elastos {
namespace Droid {
namespace Webkit {
namespace Components {

struct ElaWebContentsDelegateAndroidCallback
{
    void (*elastos_WebContentsDelegateAndroid_openNewTab)(IInterface* obj, const String& url, const String& extraHeaders, ArrayOf<Byte>* postData, Int32 disposition, Boolean isRendererInitiated);
    void (*elastos_WebContentsDelegateAndroid_activateContents)(IInterface* obj);
    void (*elastos_WebContentsDelegateAndroid_closeContents)(IInterface* obj);
    void (*elastos_WebContentsDelegateAndroid_onLoadStarted)(IInterface* obj);
    void (*elastos_WebContentsDelegateAndroid_onLoadStopped)(IInterface* obj);
    void (*elastos_WebContentsDelegateAndroid_navigationStateChanged)(IInterface* obj, Int32 flags);
    void (*elastos_WebContentsDelegateAndroid_visibleSSLStateChanged)(IInterface* obj);
    void (*elastos_WebContentsDelegateAndroid_notifyLoadProgressChanged)(IInterface* obj, Double progress);
    void (*elastos_WebContentsDelegateAndroid_rendererUnresponsive)(IInterface* obj);
    void (*elastos_WebContentsDelegateAndroid_rendererResponsive)(IInterface* obj);
    void (*elastos_WebContentsDelegateAndroid_onUpdateUrl)(IInterface* obj, const String& url);
    Boolean (*elastos_WebContentsDelegateAndroid_takeFocus)(IInterface* obj, Boolean reverse);
    void (*elastos_WebContentsDelegateAndroid_handleKeyboardEvent)(IInterface* obj, IInterface* event);
    Boolean (*elastos_WebContentsDelegateAndroid_addMessageToConsole)(IInterface* obj, Int32 level, const String& message, Int32 lineNumber, const String& sourceId);
    void (*elastos_WebContentsDelegateAndroid_showRepostFormWarningDialog)(IInterface* obj, IInterface* contentViewCore);
    void (*elastos_WebContentsDelegateAndroid_toggleFullscreenModeForTab)(IInterface* obj, Boolean enterFullscreen);
    Boolean (*elastos_WebContentsDelegateAndroid_isFullscreenForTabOrPending)(IInterface* obj);
};

void* WebContentsDelegateElastos::ElaWebContentsDelegateElastosCallback_Init()
{
    static ElaWebContentsDelegateAndroidCallback sElaWebContentsDelegateAndroidCallback;

    sElaWebContentsDelegateAndroidCallback.elastos_WebContentsDelegateAndroid_openNewTab = &WebContentsDelegateElastos::OpenNewTab;
    sElaWebContentsDelegateAndroidCallback.elastos_WebContentsDelegateAndroid_activateContents = &WebContentsDelegateElastos::ActivateContents;
    sElaWebContentsDelegateAndroidCallback.elastos_WebContentsDelegateAndroid_closeContents = &WebContentsDelegateElastos::CloseContents;
    sElaWebContentsDelegateAndroidCallback.elastos_WebContentsDelegateAndroid_onLoadStarted = &WebContentsDelegateElastos::OnLoadStarted;
    sElaWebContentsDelegateAndroidCallback.elastos_WebContentsDelegateAndroid_onLoadStopped = &WebContentsDelegateElastos::OnLoadStopped;
    sElaWebContentsDelegateAndroidCallback.elastos_WebContentsDelegateAndroid_navigationStateChanged = &WebContentsDelegateElastos::NavigationStateChanged;
    sElaWebContentsDelegateAndroidCallback.elastos_WebContentsDelegateAndroid_visibleSSLStateChanged = &WebContentsDelegateElastos::VisibleSSLStateChanged;
    sElaWebContentsDelegateAndroidCallback.elastos_WebContentsDelegateAndroid_notifyLoadProgressChanged = &WebContentsDelegateElastos::NotifyLoadProgressChanged;
    sElaWebContentsDelegateAndroidCallback.elastos_WebContentsDelegateAndroid_rendererUnresponsive = &WebContentsDelegateElastos::RendererUnresponsive;
    sElaWebContentsDelegateAndroidCallback.elastos_WebContentsDelegateAndroid_rendererResponsive = &WebContentsDelegateElastos::RendererResponsive;
    sElaWebContentsDelegateAndroidCallback.elastos_WebContentsDelegateAndroid_onUpdateUrl = &WebContentsDelegateElastos::OnUpdateUrl;
    sElaWebContentsDelegateAndroidCallback.elastos_WebContentsDelegateAndroid_takeFocus = &WebContentsDelegateElastos::TakeFocus;
    sElaWebContentsDelegateAndroidCallback.elastos_WebContentsDelegateAndroid_handleKeyboardEvent = &WebContentsDelegateElastos::HandleKeyboardEvent;
    sElaWebContentsDelegateAndroidCallback.elastos_WebContentsDelegateAndroid_addMessageToConsole = &WebContentsDelegateElastos::AddMessageToConsole;
    sElaWebContentsDelegateAndroidCallback.elastos_WebContentsDelegateAndroid_showRepostFormWarningDialog = &WebContentsDelegateElastos::ShowRepostFormWarningDialog;
    sElaWebContentsDelegateAndroidCallback.elastos_WebContentsDelegateAndroid_toggleFullscreenModeForTab = &WebContentsDelegateElastos::ToggleFullscreenModeForTab;
    sElaWebContentsDelegateAndroidCallback.elastos_WebContentsDelegateAndroid_isFullscreenForTabOrPending = &WebContentsDelegateElastos::IsFullscreenForTabOrPending;

    Elastos_WebContentsDelegateAndroid_InitCallback((Handle32)&sElaWebContentsDelegateAndroidCallback);
    return &sElaWebContentsDelegateAndroidCallback;
}

static void* sPElaWebContentsDelegateElastosCallback = WebContentsDelegateElastos::ElaWebContentsDelegateElastosCallback_Init();

} // namespace Components
} // namespace Webkit
} // namespace Droid
} // namespace Elastos

#endif //ELASTOS_WEBCONTENTSDELEGATEANDROID_CALLBACK_DEC_HH
