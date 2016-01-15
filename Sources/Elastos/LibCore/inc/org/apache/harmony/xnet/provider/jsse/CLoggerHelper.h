
#ifndef __ORG_APACHE_HARMONY_XNET_PROVIDER_JSSE_CLOGGERHELPER_H__
#define __ORG_APACHE_HARMONY_XNET_PROVIDER_JSSE_CLOGGERHELPER_H__

#include "_Org_Apache_Harmony_Xnet_Provider_Jsse_CLoggerHelper.h"

namespace Org {
namespace Apache {
namespace Harmony {
namespace Xnet {
namespace Provider {
namespace Jsse {

CarClass(CLoggerHelper)
{
public:
    CARAPI GetStream(
        /* [in] */ const String& name,
        /* [out] */ Org::Apache::Harmony::Xnet::Provider::Jsse::ILoggerStream ** ppStream);

private:
    // TODO: Add your private member variables here.
};

}
}
}
}
}
}

#endif // __ORG_APACHE_HARMONY_XNET_PROVIDER_JSSE_CLOGGERHELPER_H__
