//This file is autogenerated for
//    MediaResourceGetter.java
//put this file at the end of the include list
//so the type definition used in this file will be found
#ifndef ELASTOS_MEDIARESOURCEGETTER_CALLBACK_DEC_HH
#define ELASTOS_MEDIARESOURCEGETTER_CALLBACK_DEC_HH


#ifdef __cplusplus
extern "C"
{
#endif
    extern void Elastos_MediaResourceGetter_InitCallback(Handle32 cb);
#ifdef __cplusplus
}
#endif

namespace Elastos {
namespace Droid {
namespace Webkit {
namespace Webview {
namespace Chromium {
namespace Content {
namespace Browser {

struct ElaMediaResourceGetterCallback
{
    Int32 (*elastos_MediaMetadata_getDurationInMilliseconds)(IInterface* obj);
    Int32 (*elastos_MediaMetadata_getWidth)(IInterface* obj);
    Int32 (*elastos_MediaMetadata_getHeight)(IInterface* obj);
    Boolean (*elastos_MediaMetadata_isSuccess)(IInterface* obj);
    AutoPtr<IInterface> (*elastos_MediaResourceGetter_extractMediaMetadata)(IInterface* context, const String& url, const String& cookies, const String& userAgent);
    AutoPtr<IInterface> (*elastos_MediaResourceGetter_extractMediaMetadataFromFd)(Int32 fd, Int64 offset, Int64 length);
};

void* MediaResourceGetter::ElaMediaResourceGetterCallback_Init()
{
    static ElaMediaResourceGetterCallback sElaMediaResourceGetterCallback;

    sElaMediaResourceGetterCallback.elastos_MediaMetadata_getDurationInMilliseconds = &MediaResourceGetter::MediaMetadata::GetDurationInMilliseconds;
    sElaMediaResourceGetterCallback.elastos_MediaMetadata_getWidth = &MediaResourceGetter::MediaMetadata::GetWidth;
    sElaMediaResourceGetterCallback.elastos_MediaMetadata_getHeight = &MediaResourceGetter::MediaMetadata::GetHeight;
    sElaMediaResourceGetterCallback.elastos_MediaMetadata_isSuccess = &MediaResourceGetter::MediaMetadata::IsSuccess;
    sElaMediaResourceGetterCallback.elastos_MediaResourceGetter_extractMediaMetadata = &MediaResourceGetter::ExtractMediaMetadata;
    sElaMediaResourceGetterCallback.elastos_MediaResourceGetter_extractMediaMetadataFromFd = &MediaResourceGetter::ExtractMediaMetadataFromFd;

    Elastos_MediaResourceGetter_InitCallback((Handle32)&sElaMediaResourceGetterCallback);
    return &sElaMediaResourceGetterCallback;
}

static void* sPElaMediaResourceGetterCallback = MediaResourceGetter::ElaMediaResourceGetterCallback_Init();

} // namespace Browser
} // namespace Content
} // namespace Chromium
} // namespace Webview
} // namespace Webkit
} // namespace Droid
} // namespace Elastos

#endif //ELASTOS_MEDIARESOURCEGETTER_CALLBACK_DEC_HH