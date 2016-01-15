
#ifndef __ELASTOS_DROID_NET_WIFI_P2P_NSD_CWIFIP2PUPNPSERVICERESPONSEHELPER_H__
#define __ELASTOS_DROID_NET_WIFI_P2P_NSD_CWIFIP2PUPNPSERVICERESPONSEHELPER_H__

#include "_Elastos_Droid_Wifi_P2p_Nsd_CWifiP2pUpnpServiceResponseHelper.h"

using Elastos::Droid::Wifi::P2p::IWifiP2pDevice;

namespace Elastos {
namespace Droid {
namespace Wifi {
namespace P2p {
namespace Nsd {

CarClass(CWifiP2pUpnpServiceResponseHelper)
{
public:
    CARAPI NewInstance(
        /* [in] */ Int32 status,
        /* [in] */ Int32 transId,
        /* [in] */ IWifiP2pDevice* dev,
        /* [in] */ ArrayOf<Byte>* data,
        /* [out] */ IWifiP2pUpnpServiceResponse** instance);
};

} // namespace Nsd
} // namespace P2p
} // namespace Wifi
} // namespace Droid
} // namespace Elastos

#endif // __ELASTOS_DROID_NET_WIFI_P2P_NSD_CWIFIP2PUPNPSERVICERESPONSEHELPER_H__
