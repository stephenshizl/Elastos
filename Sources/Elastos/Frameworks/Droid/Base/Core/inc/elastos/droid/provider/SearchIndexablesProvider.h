#ifndef __ELASTOS_DROID_PROVIDER_SEARCHINDEXABLESPROVIDER_H__
#define __ELASTOS_DROID_PROVIDER_SEARCHINDEXABLESPROVIDER_H__

// #include "Elastos.Droid.Content.h"
#include "Elastos.Droid.Provider.h"
#include "elastos/droid/ext/frameworkext.h"
#include "elastos/droid/content/ContentProvider.h"

using Elastos::Droid::Content::IContentValues;
using Elastos::Droid::Content::IContext;
using Elastos::Droid::Content::ContentProvider;
using Elastos::Droid::Content::IUriMatcher;
using Elastos::Droid::Content::Pm::IProviderInfo;
using Elastos::Droid::Database::ICursor;
using Elastos::Droid::Net::IUri;

namespace Elastos {
namespace Droid {
namespace Provider {

class ECO_PUBLIC SearchIndexablesProvider
    : public ContentProvider
    , public ISearchIndexablesProvider
{
public:
    SearchIndexablesProvider();

    virtual ~SearchIndexablesProvider();

    CAR_INTERFACE_DECL()

    CARAPI constructor();

    /**
     * Implementation is provided by the parent class.
     */
    //@Override
    CARAPI AttachInfo(
        /* [in] */ IContext* context,
        /* [in] */ IProviderInfo* info);

    //@Override
    CARAPI Query(
        /* [in] */ IUri* uri,
        /* [in] */ ArrayOf<String>* projection,
        /* [in] */ const String& selection,
        /* [in] */ ArrayOf<String>* selectionArgs,
        /* [in] */ const String& sortOrder,
        /* [out] */ ICursor** cursor);

    virtual CARAPI QueryXmlResources(
        /* [in] */ ArrayOf<String>* projection,
        /* [out] */ ICursor** cursor) = 0;

    virtual CARAPI QueryRawData(
        /* [in] */ ArrayOf<String>* projection,
        /* [out] */ ICursor** cursor) = 0;

    virtual CARAPI QueryNonIndexableKeys(
        /* [in] */ ArrayOf<String>* projection,
        /* [out] */ ICursor** cursor) = 0;

    //@Override
    CARAPI GetType(
        /* [in] */ IUri* uri,
        /* [out] */ String* result);

    /**
     * Implementation is provided by the parent class. Throws by default, and cannot be overriden.
     */
    //@Override
    CARAPI Insert(
        /* [in] */ IUri* uri,
        /* [in] */ IContentValues* values,
        /* [out] */ IUri** insertedUri);

    /**
     * Implementation is provided by the parent class. Throws by default, and cannot be overriden.
     */
    //@Override
    CARAPI Delete(
        /* [in] */ IUri* uri,
        /* [in] */ const String& selection,
        /* [in] */ ArrayOf<String>* selectionArgs,
        /* [out] */ Int32* rowsAffected);

    /**
     * Implementation is provided by the parent class. Throws by default, and cannot be overriden.
     */
    //@Override
    CARAPI Update(
        /* [in] */ IUri* uri,
        /* [in] */ IContentValues* values,
        /* [in] */ const String& selection,
        /* [in] */ ArrayOf<String>* selectionArgs,
        /* [out] */ Int32* rowsAffected);

private:
    ECO_LOCAL const static String TAG;
    String mAuthority;
    AutoPtr<IUriMatcher> mMatcher;
    ECO_LOCAL static const Int32 MATCH_RES_CODE;
    ECO_LOCAL static const Int32 MATCH_RAW_CODE;
    ECO_LOCAL static const Int32 MATCH_NON_INDEXABLE_KEYS_CODE;
};

} // namespace Provider
} // namespace Droid
} // namespace Elastos

#endif // __ELASTOS_DROID_PROVIDER_SEARCHINDEXABLESPROVIDER_H__
