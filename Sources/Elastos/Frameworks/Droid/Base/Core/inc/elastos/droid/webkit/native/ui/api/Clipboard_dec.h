//This file is autogenerated for
//    Clipboard.java
//put this file at the end of the include list
//so the type definition used in this file will be found
#ifndef ELASTOS_CLIPBOARD_CALLBACK_DEC_HH
#define ELASTOS_CLIPBOARD_CALLBACK_DEC_HH


#ifdef __cplusplus
extern "C"
{
#endif
    extern void Elastos_Clipboard_InitCallback(Handle32 cb);
#ifdef __cplusplus
}
#endif

namespace Elastos {
namespace Droid {
namespace Webkit {
namespace Ui {
namespace Base {

struct ElaClipboardCallback
{
    AutoPtr<IInterface> (*elastos_Clipboard_create)(IInterface* context);
    String (*elastos_Clipboard_getCoercedText)(IInterface* obj);
    String (*elastos_Clipboard_getHTMLText)(IInterface* obj);
    void (*elastos_Clipboard_setText)(IInterface* obj, const String& text);
    void (*elastos_Clipboard_setHTMLText)(IInterface* obj, const String& html, const String& text);
    Boolean (*elastos_Clipboard_isHTMLClipboardSupported)();
};

void* Clipboard::ElaClipboardCallback_Init()
{
    static ElaClipboardCallback sElaClipboardCallback;

    sElaClipboardCallback.elastos_Clipboard_create = &Clipboard::Create;
    sElaClipboardCallback.elastos_Clipboard_getCoercedText = &Clipboard::GetCoercedText;
    sElaClipboardCallback.elastos_Clipboard_getHTMLText = &Clipboard::GetHTMLText;
    sElaClipboardCallback.elastos_Clipboard_setText = &Clipboard::SetText;
    sElaClipboardCallback.elastos_Clipboard_setHTMLText = &Clipboard::SetHTMLText;
    sElaClipboardCallback.elastos_Clipboard_isHTMLClipboardSupported = &Clipboard::IsHTMLClipboardSupported;

    Elastos_Clipboard_InitCallback((Handle32)&sElaClipboardCallback);
    return &sElaClipboardCallback;
}

static void* sPElaClipboardCallback = Clipboard::ElaClipboardCallback_Init();

} // namespace Base
} // namespace Ui
} // namespace Webkit
} // namespace Droid
} // namespace Elastos

#endif //ELASTOS_CLIPBOARD_CALLBACK_DEC_HH
