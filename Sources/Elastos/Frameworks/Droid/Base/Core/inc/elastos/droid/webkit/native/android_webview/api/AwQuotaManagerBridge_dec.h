//This file is autogenerated for
//    AwQuotaManagerBridge.java
//put this file at the end of the include list
//so the type definition used in this file will be found
#ifndef ELASTOS_AWQUOTAMANAGERBRIDGE_CALLBACK_DEC_HH
#define ELASTOS_AWQUOTAMANAGERBRIDGE_CALLBACK_DEC_HH


#ifdef __cplusplus
extern "C"
{
#endif
    extern Int64 Elastos_AwQuotaManagerBridge_nativeGetDefaultNativeAwQuotaManagerBridge();
    extern void Elastos_AwQuotaManagerBridge_nativeInit(IInterface* caller,Handle32 nativeAwQuotaManagerBridgeImpl);
    extern void Elastos_AwQuotaManagerBridge_nativeDeleteAllData(IInterface* caller,Handle32 nativeAwQuotaManagerBridgeImpl);
    extern void Elastos_AwQuotaManagerBridge_nativeDeleteOrigin(IInterface* caller,Handle32 nativeAwQuotaManagerBridgeImpl,const String& origin);
    extern void Elastos_AwQuotaManagerBridge_nativeGetOrigins(IInterface* caller,Handle32 nativeAwQuotaManagerBridgeImpl,Int32 callbackId);
    extern void Elastos_AwQuotaManagerBridge_nativeGetUsageAndQuotaForOrigin(IInterface* caller,Handle32 nativeAwQuotaManagerBridgeImpl,const String& origin,Int32 callbackId,Boolean isQuota);
    extern void Elastos_AwQuotaManagerBridge_InitCallback(Handle32 cb);
#ifdef __cplusplus
}
#endif


namespace Elastos {
namespace Droid {
namespace Webkit {
namespace AndroidWebview {

struct ElaAwQuotaManagerBridgeCallback
{
    void (*elastos_AwQuotaManagerBridge_onGetOriginsCallback)(IInterface* obj, Int32 callbackId, ArrayOf<String>* origin, ArrayOf<Int64>* usages, ArrayOf<Int64>* quotas);
    void (*elastos_AwQuotaManagerBridge_onGetUsageAndQuotaForOriginCallback)(IInterface* obj, Int32 callbackId, Boolean isQuota, Int64 usage, Int64 quota);
};

void* AwQuotaManagerBridge::ElaAwQuotaManagerBridgeCallback_Init()
{
    static ElaAwQuotaManagerBridgeCallback sElaAwQuotaManagerBridgeCallback;

    sElaAwQuotaManagerBridgeCallback.elastos_AwQuotaManagerBridge_onGetOriginsCallback = &AwQuotaManagerBridge::OnGetOriginsCallback;
    sElaAwQuotaManagerBridgeCallback.elastos_AwQuotaManagerBridge_onGetUsageAndQuotaForOriginCallback = &AwQuotaManagerBridge::OnGetUsageAndQuotaForOriginCallback;

    Elastos_AwQuotaManagerBridge_InitCallback((Handle32)&sElaAwQuotaManagerBridgeCallback);
    return &sElaAwQuotaManagerBridgeCallback;
}

static void* sPElaAwQuotaManagerBridgeCallback = AwQuotaManagerBridge::ElaAwQuotaManagerBridgeCallback_Init();

} // namespace AndroidWebview
} // namespace Webkit
} // namespace Droid
} // namespace Elastos

#endif //ELASTOS_AWQUOTAMANAGERBRIDGE_CALLBACK_DEC_HH
