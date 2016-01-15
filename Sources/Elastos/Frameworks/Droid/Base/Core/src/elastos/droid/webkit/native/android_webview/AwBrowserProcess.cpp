
#include <Elastos.CoreLibrary.IO.h>
#include <Elastos.CoreLibrary.Utility.h>
#include "Elastos.Droid.Content.h"
#include "elastos/droid/webkit/native/android_webview/AwBrowserProcess.h"
#include "elastos/droid/webkit/native/android_webview/AwResource.h"
#include "elastos/droid/webkit/native/base/ThreadUtils.h"
#include "elastos/droid/webkit/native/base/PathUtils.h"
#include "elastos/droid/webkit/native/content/browser/BrowserStartupController.h"
#include "elastos/droid/webkit/native/media/MediaDrmBridge.h"
#include <elastos/utility/logging/Logger.h>

using Elastos::Droid::Webkit::Base::ThreadUtils;
using Elastos::Droid::Webkit::Base::PathUtils;
using Elastos::Droid::Webkit::Content::Browser::BrowserStartupController;
using Elastos::Droid::Webkit::Media::MediaDrmBridge;

using Elastos::Core::StringUtils;
using Elastos::Core::EIID_IRunnable;
using Elastos::Utility::IUUID;
using Elastos::Utility::IUUIDHelper;
using Elastos::Utility::CUUIDHelper;
using Elastos::Utility::Logging::Logger;

namespace Elastos {
namespace Droid {
namespace Webkit {
namespace AndroidWebview {

//===============================================================
//               AwBrowserProcess::InnerRunnable
//===============================================================
CAR_INTERFACE_IMPL(AwBrowserProcess::InnerRunnable, Object, IRunnable);

AwBrowserProcess::InnerRunnable::InnerRunnable(
    /* [in] */ IContext* context)
    : mContext(context)
{
}

ECode AwBrowserProcess::InnerRunnable::Run()
{
    //try {
        BrowserStartupController::Get(mContext)->StartBrowserProcessesSync(
                    BrowserStartupController::MAX_RENDERERS_SINGLE_PROCESS);
        InitializePlatformKeySystem();
    //} catch (ProcessInitException e) {
    //    throw new RuntimeException("Cannot initialize WebView", e);
    //}
    return NOERROR;
}

//===============================================================
//                      AwBrowserProcess
//===============================================================

const String AwBrowserProcess::PRIVATE_DATA_DIRECTORY_SUFFIX("webview");
const String AwBrowserProcess::TAG("AwBrowserProcess");

/**
 * Loads the native library, and performs basic static construction of objects needed
 * to run webview in this process. Does not create threads; safe to call from zygote.
 * Note: it is up to the caller to ensure this is only called once.
 */
void AwBrowserProcess::LoadLibrary()
{
    PathUtils::SetPrivateDataDirectorySuffix(PRIVATE_DATA_DIRECTORY_SUFFIX);
    /*
    try {
        LibraryLoader.loadNow();
    } catch (ProcessInitException e) {
        throw new RuntimeException("Cannot load WebView", e);
    }
    */
    Logger::E(TAG, "AwBrowserProcess::LoadLibrary, why load library...?");
    assert(0);
}

/**
 * Starts the chromium browser process running within this process. Creates threads
 * and performs other per-app resource allocations; must not be called from zygote.
 * Note: it is up to the caller to ensure this is only called once.
 * @param context The Android application context
 */
void AwBrowserProcess::Start(
    /* [in] */ IContext* context)
{
    // We must post to the UI thread to cover the case that the user
    // has invoked Chromium startup by using the (thread-safe)
    // CookieManager rather than creating a WebView.
    AutoPtr<IRunnable> runnable = new InnerRunnable(context);
    ThreadUtils::RunOnUiThreadBlocking(runnable);
}

void AwBrowserProcess::InitializePlatformKeySystem()
{
    AutoPtr<ArrayOf<String> > mappings = AwResource::GetConfigKeySystemUuidMapping();
    Int32 length = mappings->GetLength();
    for (Int32 i = 0; i < length; ++i) {
        //try {
        //String fragments[] = mapping.split(",");
        AutoPtr<ArrayOf<String> > fragments;
        StringUtils::Split((*mappings)[i], ",", (ArrayOf<String>**)&fragments);
        String keySystem = (*fragments)[0].Trim();
        //UUID uuid = UUID.fromString(fragments[1]);
        AutoPtr<IUUID> uuid;
        AutoPtr<IUUIDHelper> helper;
        CUUIDHelper::AcquireSingleton((IUUIDHelper**)&helper);
        helper->FromString((*fragments)[1], (IUUID**)&uuid);
        MediaDrmBridge::AddKeySystemUuidMapping(keySystem, uuid);
        //} catch (java.lang.RuntimeException e) {
        //    Log.e(TAG, "Can't parse key-system mapping: " + mapping);
        //}
    }
}

} // namespace AndroidWebview
} // namespace Webkit
} // namespace Droid
} // namespace Elastos
