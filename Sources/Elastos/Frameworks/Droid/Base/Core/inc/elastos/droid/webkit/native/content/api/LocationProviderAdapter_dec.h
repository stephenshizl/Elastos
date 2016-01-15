//This file is autogenerated for
//    LocationProviderAdapter.java
//put this file at the end of the include list
//so the type definition used in this file will be found
#ifndef ELASTOS_LOCATIONPROVIDERADAPTER_CALLBACK_DEC_HH
#define ELASTOS_LOCATIONPROVIDERADAPTER_CALLBACK_DEC_HH


#ifdef __cplusplus
extern "C"
{
#endif
    extern void Elastos_LocationProviderAdapter_nativeNewLocationAvailable(Double latitude,Double longitude,Double timeStamp,Boolean hasAltitude,Double altitude,Boolean hasAccuracy,Double accuracy,Boolean hasHeading,Double heading,Boolean hasSpeed,Double speed);
    extern void Elastos_LocationProviderAdapter_nativeNewErrorAvailable(const String& message);
    extern void Elastos_LocationProviderAdapter_InitCallback(Handle32 cb);
#ifdef __cplusplus
}
#endif


namespace Elastos {
namespace Droid {
namespace Webkit {
namespace Content {
namespace Browser {

struct ElaLocationProviderAdapterCallback
{
    AutoPtr<IInterface> (*elastos_LocationProviderAdapter_create)(IInterface* context);
    Boolean (*elastos_LocationProviderAdapter_start)(IInterface* obj, Boolean gpsEnabled);
    void (*elastos_LocationProviderAdapter_stop)(IInterface* obj);
};

void* LocationProviderAdapter::ElaLocationProviderAdapterCallback_Init()
{
    static ElaLocationProviderAdapterCallback sElaLocationProviderAdapterCallback;

    sElaLocationProviderAdapterCallback.elastos_LocationProviderAdapter_create = &LocationProviderAdapter::Create;
    sElaLocationProviderAdapterCallback.elastos_LocationProviderAdapter_start = &LocationProviderAdapter::Start;
    sElaLocationProviderAdapterCallback.elastos_LocationProviderAdapter_stop = &LocationProviderAdapter::Stop;

    Elastos_LocationProviderAdapter_InitCallback((Handle32)&sElaLocationProviderAdapterCallback);
    return &sElaLocationProviderAdapterCallback;
}

static void* sPElaLocationProviderAdapterCallback = LocationProviderAdapter::ElaLocationProviderAdapterCallback_Init();

} // namespace Browser
} // namespace Content
} // namespace Webkit
} // namespace Droid
} // namespace Elastos

#endif //ELASTOS_LOCATIONPROVIDERADAPTER_CALLBACK_DEC_HH
