//This file is autogenerated for
//    AndroidPrivateKey.java
//put this file at the end of the include list
//so the type definition used in this file will be found
#ifndef ELASTOS_ANDROIDPRIVATEKEY_CALLBACK_DEC_HH
#define ELASTOS_ANDROIDPRIVATEKEY_CALLBACK_DEC_HH


#ifdef __cplusplus
extern "C"
{
#endif
    extern void Elastos_AndroidPrivateKey_InitCallback(Handle32 cb);
#ifdef __cplusplus
}
#endif

namespace Elastos {
namespace Droid {
namespace Webkit {
namespace Net {

struct ElaAndroidPrivateKeyCallback
{
    AutoPtr<IInterface> (*elastos_AndroidPrivateKey_getKeyStore)(IInterface* obj);
};

void* ElastosPrivateKey::ElaElastosPrivateKeyCallback_Init()
{
    static ElaAndroidPrivateKeyCallback sElaAndroidPrivateKeyCallback;

    sElaAndroidPrivateKeyCallback.elastos_AndroidPrivateKey_getKeyStore = &ElastosPrivateKey::GetKeyStore;

    Elastos_AndroidPrivateKey_InitCallback((Handle32)&sElaAndroidPrivateKeyCallback);
    return &sElaAndroidPrivateKeyCallback;
}

static void* sPElaElastosPrivateKeyCallback = ElastosPrivateKey::ElaElastosPrivateKeyCallback_Init();

} // namespace Net
} // namespace Webkit
} // namespace Droid
} // namespace Elastos

#endif //ELASTOS_ANDROIDPRIVATEKEY_CALLBACK_DEC_HH
