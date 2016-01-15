
#ifndef __ELASTOS_DROID_WEBKIT_CONTENT_BROWSER_FRAMEHOST_NAVIGATIONCONTROLLERIMPL_H__
#define __ELASTOS_DROID_WEBKIT_CONTENT_BROWSER_FRAMEHOST_NAVIGATIONCONTROLLERIMPL_H__

#include "elastos/droid/ext/frameworkext.h"
#include "elastos/droid/webkit/native/content_public/browser/NavigationController.h"

using Elastos::Droid::Webkit::Content_Public::Browser::NavigationController;

namespace Elastos {
namespace Droid {
namespace Webkit {
namespace Content {
namespace Browser {
namespace Framehost {

// import org.chromium.base.CalledByNative;
// import org.chromium.base.JNINamespace;
// import org.chromium.content_public.browser.NavigationController;

/**
 * The NavigationControllerImpl Java wrapper to allow communicating with the native
 * NavigationControllerImpl object.
 */
//@JNINamespace("content")
// TODO(tedchoc): Remove the package restriction once this class moves to a non-public content
//                package whose visibility will be enforced via DEPS.
/* package */
class NavigationControllerImpl
    : public NavigationController
{
public:
    //@Override
    CARAPI_(Boolean) CanGoBack();

    //@Override
    CARAPI_(Boolean) CanGoForward();

    //@Override
    CARAPI_(Boolean) CanGoToOffset(
        /* [in] */ Int32 offset);

    //@Override
    CARAPI_(void) GoToOffset(
        /* [in] */ Int32 offset);

    //@Override
    CARAPI_(void) GoToNavigationIndex(
        /* [in] */ Int32 index);

    //@Override
    CARAPI_(void) GoBack();

    //@Override
    CARAPI_(void) GoForward();

    static CARAPI_(void*) ElaNavigationControllerImplCallback_Init();

private:
    static CARAPI_(void) Destroy(
        /* [in] */ IInterface* obj);

    NavigationControllerImpl(
        /* [in] */ Int64 nativeNavigationControllerAndroid);

    //@CalledByNative return NavigationControllerImpl
    static CARAPI_(AutoPtr<IInterface>) Create(
        /* [in] */ Int64 nativeNavigationControllerAndroid);

    //@CalledByNative
    CARAPI_(void) Destroy();

    CARAPI_(Boolean) NativeCanGoBack(
        /* [in] */ Int64 nativeNavigationControllerAndroid);

    CARAPI_(Boolean) NativeCanGoForward(
        /* [in] */ Int64 nativeNavigationControllerAndroid);

    CARAPI_(Boolean) NativeCanGoToOffset(
        /* [in] */ Int64 nativeNavigationControllerAndroid,
        /* [in] */ Int32 offset);

    CARAPI_(void) NativeGoBack(
        /* [in] */ Int64 nativeNavigationControllerAndroid);

    CARAPI_(void) NativeGoForward(
        /* [in] */ Int64 nativeNavigationControllerAndroid);

    CARAPI_(void) NativeGoToOffset(
        /* [in] */ Int64 nativeNavigationControllerAndroid,
        /* [in] */ Int32 offset);

    CARAPI_(void) NativeGoToNavigationIndex(
        /* [in] */ Int64 nativeNavigationControllerAndroid,
        /* [in] */ Int32 index);

private:
    Int64 mNativeNavigationControllerAndroid;
};

} // namespace Framehost
} // namespace Browser
} // namespace Content
} // namespace Webkit
} // namespace Droid
} // namespace Elastos

#endif//__ELASTOS_DROID_WEBKIT_CONTENT_BROWSER_FRAMEHOST_NAVIGATIONCONTROLLERIMPL_H__
