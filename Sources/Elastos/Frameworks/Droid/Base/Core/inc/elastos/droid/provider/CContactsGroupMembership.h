#ifndef __ELASTOS_DROID_PROVIDER_CCONTACTSGROUPMEMBERSHIP_H__
#define __ELASTOS_DROID_PROVIDER_CCONTACTSGROUPMEMBERSHIP_H__

#include "_Elastos_Droid_Provider_CContactsGroupMembership.h"
#include <elastos/core/Singleton.h>

using Elastos::Droid::Net::IUri;

namespace Elastos {
namespace Droid {
namespace Provider {

CarClass(CContactsGroupMembership)
    , public Singleton
    , public IContactsGroupMembership
    , public IBaseColumns
    , public IContactsGroupsColumns
{
public:
    CAR_SINGLETON_DECL()

    CAR_INTERFACE_DECL()

    /**
     * no public constructor since this is a utility class
     */
    CARAPI constructor();

    /**
     * The content:// style URL for this table
     * @deprecated see {@link android.provider.ContactsContract}
     */
    //@Deprecated
    CARAPI GetCONTENT_URI(
        /* [out] */ IUri** uri);

    /**
     * The content:// style URL for this table
     * @deprecated see {@link android.provider.ContactsContract}
     */
    //@Deprecated
    CARAPI GetRAW_CONTENT_URL(
        /* [out] */ IUri** uri);
};

} // Provider
} // Droid
} // Elastos

#endif //__ELASTOS_DROID_PROVIDER_CCONTACTSGROUPMEMBERSHIP_H__
