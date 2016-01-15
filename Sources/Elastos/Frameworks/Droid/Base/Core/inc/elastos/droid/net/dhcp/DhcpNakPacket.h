
#ifndef __ELASTOS_DROID_NET_DHCP_DHCPNAKPACKET_H__
#define __ELASTOS_DROID_NET_DHCP_DHCPNAKPACKET_H__

#include "elastos/droid/ext/frameworkext.h"
#include "elastos/droid/net/dhcp/DhcpPacket.h"

namespace Elastos {
namespace Droid {
namespace Net {
namespace Dhcp {

/**
 * This class implements the DHCP-NAK packet.
 */
class DhcpNakPacket
    : public DhcpPacket
{
public:
    DhcpNakPacket();

    /**
     * Generates a NAK packet with the specified parameters.
     */
    CARAPI constructor(
        /* [in] */ Int32 transId,
        /* [in] */ IInetAddress* clientIp,
        /* [in] */ IInetAddress* yourIp,
        /* [in] */ IInetAddress* nextIp,
        /* [in] */ IInetAddress* relayIp,
        /* [in] */ ArrayOf<Byte>* clientMac);

    CARAPI ToString(
        /* [out] */ String* result);

    /**
     * Fills in a packet with the requested NAK attributes.
     */
    CARAPI BuildPacket(
        /* [in] */ Int32 encap,
        /* [in] */ Int16 destUdp,
        /* [in] */ Int16 srcUdp,
        /* [out] */ IByteBuffer** result);

    /**
     * Adds the optional parameters to the client-generated NAK packet.
     */
    CARAPI FinishPacket(
        /* [in] */ IByteBuffer* buffer);

    /**
     * Notifies the specified state machine of the newly-arrived NAK packet.
     */
    CARAPI DoNextOp(
        /* [in] */ DhcpStateMachine* machine);
};

} // namespace Dhcp
} // namespace Net
} // namespace Droid
} // namespace Elastos

#endif // __ELASTOS_DROID_NET_DHCP_DHCPNAKPACKET_H__
