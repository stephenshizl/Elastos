//This file is autogenerated for
//    InterstitialPageDelegateAndroid.java
//put this file at the end of the include list
//so the type definition used in this file will be found
#ifndef ELASTOS_INTERSTITIALPAGEDELEGATEANDROID_CALLBACK_DEC_HH
#define ELASTOS_INTERSTITIALPAGEDELEGATEANDROID_CALLBACK_DEC_HH


#ifdef __cplusplus
extern "C"
{
#endif
    extern Int64 Elastos_InterstitialPageDelegateAndroid_nativeInit(IInterface* caller,const String& htmlContent);
    extern void Elastos_InterstitialPageDelegateAndroid_nativeProceed(IInterface* caller,Handle32 nativeInterstitialPageDelegateElastos);
    extern void Elastos_InterstitialPageDelegateAndroid_nativeDontProceed(IInterface* caller,Handle32 nativeInterstitialPageDelegateElastos);
    extern void Elastos_InterstitialPageDelegateAndroid_InitCallback(Handle32 cb);
#ifdef __cplusplus
}
#endif


namespace Elastos {
namespace Droid {
namespace Webkit {
namespace Content {
namespace Browser {

struct ElaInterstitialPageDelegateAndroidCallback
{
    void (*elastos_InterstitialPageDelegateAndroid_onProceed)(IInterface* obj);
    void (*elastos_InterstitialPageDelegateAndroid_onDontProceed)(IInterface* obj);
    void (*elastos_InterstitialPageDelegateAndroid_commandReceived)(IInterface* obj, const String& command);
    void (*elastos_InterstitialPageDelegateAndroid_onNativeDestroyed)(IInterface* obj);
};

void* InterstitialPageDelegateElastos::ElaInterstitialPageDelegateElastosCallback_Init()
{
    static ElaInterstitialPageDelegateAndroidCallback sElaInterstitialPageDelegateAndroidCallback;

    sElaInterstitialPageDelegateAndroidCallback.elastos_InterstitialPageDelegateAndroid_onProceed = &InterstitialPageDelegateElastos::OnProceed;
    sElaInterstitialPageDelegateAndroidCallback.elastos_InterstitialPageDelegateAndroid_onDontProceed = &InterstitialPageDelegateElastos::OnDontProceed;
    sElaInterstitialPageDelegateAndroidCallback.elastos_InterstitialPageDelegateAndroid_commandReceived = &InterstitialPageDelegateElastos::CommandReceived;
    sElaInterstitialPageDelegateAndroidCallback.elastos_InterstitialPageDelegateAndroid_onNativeDestroyed = &InterstitialPageDelegateElastos::OnNativeDestroyed;

    Elastos_InterstitialPageDelegateAndroid_InitCallback((Handle32)&sElaInterstitialPageDelegateAndroidCallback);
    return &sElaInterstitialPageDelegateAndroidCallback;
}

static void* sPElaInterstitialPageDelegateElastosCallback = InterstitialPageDelegateElastos::ElaInterstitialPageDelegateElastosCallback_Init();

} // namespace Browser
} // namespace Content
} // namespace Webkit
} // namespace Droid
} // namespace Elastos

#endif //ELASTOS_INTERSTITIALPAGEDELEGATEANDROID_CALLBACK_DEC_HH
