//=========================================================================
// Copyright (C) 2012 The Elastos Open Source Project
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//      http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//=========================================================================

#ifndef __ELASTOS_DROID_WEBKIT_WEBVIEW_CHROMIUM_CONTENT_BROWSER_ACCESSIBILITY_KITKATBROWSERACCESSIBILITYManager_H__
#define __ELASTOS_DROID_WEBKIT_WEBVIEW_CHROMIUM_CONTENT_BROWSER_ACCESSIBILITY_KITKATBROWSERACCESSIBILITYManager_H__

#include "elastos/droid/webkit/webview/chromium/native/content/browser/accessibility/JellyBeanBrowserAccessibilityManager.h"

using Elastos::Droid::View::Accessibility::IAccessibilityEvent;
using Elastos::Droid::View::Accessibility::IAccessibilityNodeInfo;

// import org.chromium.base.JNINamespace;
// import org.chromium.content.browser.ContentViewCore;

namespace Elastos {
namespace Droid {
namespace Webkit {
namespace Webview {
namespace Chromium {
namespace Content {
namespace Browser {

class ContentViewCore;

namespace Accessibility {

/**
 * Subclass of BrowserAccessibilityManager for KitKat that creates an
 * AccessibilityNodeProvider and delegates its implementation to this object.
 *
 * THIS CLASS IS NOT USED! A bug in the KitKat framework prevents us
 * from using these new APIs. We can re-enable this class after the next
 * Android system update. http://crbug.com/348088/
 */
//@JNINamespace("content")
class KitKatBrowserAccessibilityManager : public JellyBeanBrowserAccessibilityManager
{
public:
    KitKatBrowserAccessibilityManager(
        /* [in] */ Int64 nativeBrowserAccessibilityManagerAndroid,
        /* [in] */ ContentViewCore* contentViewCore);

protected:
    //@Override
    CARAPI_(void) SetAccessibilityNodeInfoKitKatAttributes(
        /* [in] */ IAccessibilityNodeInfo* node,
        /* [in] */ Boolean canOpenPopup,
        /* [in] */ Boolean contentInvalid,
        /* [in] */ Boolean dismissable,
        /* [in] */ Boolean multiLine,
        /* [in] */ Int32 inputType,
        /* [in] */ Int32 liveRegion);

    //@Override
    CARAPI_(void) SetAccessibilityNodeInfoCollectionInfo(
        /* [in] */ IAccessibilityNodeInfo* node,
        /* [in] */ Int32 rowCount,
        /* [in] */ Int32 columnCount,
        /* [in] */ Boolean hierarchical);

    //@Override
    CARAPI_(void) SetAccessibilityNodeInfoCollectionItemInfo(
        /* [in] */ IAccessibilityNodeInfo* node,
        /* [in] */ Int32 rowIndex,
        /* [in] */ Int32 rowSpan,
        /* [in] */ Int32 columnIndex,
        /* [in] */ Int32 columnSpan,
        /* [in] */ Boolean heading);

    //@Override
    CARAPI_(void) SetAccessibilityNodeInfoRangeInfo(
        /* [in] */ IAccessibilityNodeInfo* node,
        /* [in] */ Int32 rangeType,
        /* [in] */ Float min,
        /* [in] */ Float max,
        /* [in] */ Float current);

    //@Override
    CARAPI_(void) SetAccessibilityEventKitKatAttributes(
        /* [in] */ IAccessibilityEvent* event,
        /* [in] */ Boolean canOpenPopup,
        /* [in] */ Boolean contentInvalid,
        /* [in] */ Boolean dismissable,
        /* [in] */ Boolean multiLine,
        /* [in] */ Int32 inputType,
        /* [in] */ Int32 liveRegion);

    //@Override
    CARAPI_(void) SetAccessibilityEventCollectionInfo(
        /* [in] */ IAccessibilityEvent* event,
        /* [in] */ Int32 rowCount,
        /* [in] */ Int32 columnCount,
        /* [in] */ Boolean hierarchical);

    //@Override
    CARAPI_(void) SetAccessibilityEventHeadingFlag(
        /* [in] */ IAccessibilityEvent* event,
        /* [in] */ Boolean heading);

    //@Override
    CARAPI_(void) SetAccessibilityEventCollectionItemInfo(
        /* [in] */ IAccessibilityEvent* event,
        /* [in] */ Int32 rowIndex,
        /* [in] */ Int32 rowSpan,
        /* [in] */ Int32 columnIndex,
        /* [in] */ Int32 columnSpan);

    //@Override
    CARAPI_(void) SetAccessibilityEventRangeInfo(
        /* [in] */ IAccessibilityEvent* event,
        /* [in] */ Int32 rangeType,
        /* [in] */ Float min,
        /* [in] */ Float max,
        /* [in] */ Float current);
};

} // namespace Accessibility
} // namespace Browser
} // namespace Content
} // namespace Chromium
} // namespace Webview
} // namespace Webkit
} // namespace Droid
} // namespace Elastos

#endif//__ELASTOS_DROID_WEBKIT_WEBVIEW_CHROMIUM_CONTENT_BROWSER_ACCESSIBILITY_KITKATBROWSERACCESSIBILITYManager_H__
