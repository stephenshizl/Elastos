//This file is autogenerated for
//    HashSet.class
//put this file at the end of the include list
//so the type definition used in this file will be found
#ifndef ELASTOS_HASHSET_CALLBACK_DEC_HH
#define ELASTOS_HASHSET_CALLBACK_DEC_HH


#ifdef __cplusplus
extern "C"
{
#endif
    extern void Elastos_HashSet_InitCallback(Handle32 cb);
#ifdef __cplusplus
}
#endif

namespace Elastos {
namespace Droid {
namespace Webkit {
namespace Api {

struct ElaHashSetCallback
{
    Boolean (*elastos_HashSet_add)(IInterface* obj, IInterface* p0);
    void (*elastos_HashSet_clear)(IInterface* obj);
    AutoPtr<IInterface> (*elastos_HashSet_clone)(IInterface* obj);
    Boolean (*elastos_HashSet_contains)(IInterface* obj, IInterface* p0);
    Boolean (*elastos_HashSet_isEmpty)(IInterface* obj);
    AutoPtr<IInterface> (*elastos_HashSet_iterator)(IInterface* obj);
    Boolean (*elastos_HashSet_remove)(IInterface* obj, IInterface* p0);
    Int32 (*elastos_HashSet_size)(IInterface* obj);
    AutoPtr<IInterface> (*elastos_HashSet_ConstructorJUHS)();
    AutoPtr<IInterface> (*elastos_HashSet_ConstructorJUHS_I)(Int32 p0);
    AutoPtr<IInterface> (*elastos_HashSet_ConstructorJUHS_I_F)(Int32 p0, Float p1);
    AutoPtr<IInterface> (*elastos_HashSet_ConstructorJUHS_JUC)(IInterface* extends);
};

void* AwHashSet::ElaHashSetCallback_Init()
{
    static ElaHashSetCallback sElaHashSetCallback;

    sElaHashSetCallback.elastos_HashSet_add = &AwHashSet::Add;
    sElaHashSetCallback.elastos_HashSet_clear = &AwHashSet::Clear;
    sElaHashSetCallback.elastos_HashSet_clone = &AwHashSet::Clone;
    sElaHashSetCallback.elastos_HashSet_contains = &AwHashSet::Contains;
    sElaHashSetCallback.elastos_HashSet_isEmpty = &AwHashSet::IsEmpty;
    sElaHashSetCallback.elastos_HashSet_iterator = &AwHashSet::Iterator;
    sElaHashSetCallback.elastos_HashSet_remove = &AwHashSet::Remove;
    sElaHashSetCallback.elastos_HashSet_size = &AwHashSet::Size;
    sElaHashSetCallback.elastos_HashSet_ConstructorJUHS = &AwHashSet::ConstructorJUHS;
    sElaHashSetCallback.elastos_HashSet_ConstructorJUHS_I = &AwHashSet::ConstructorJUHSI;
    sElaHashSetCallback.elastos_HashSet_ConstructorJUHS_I_F = &AwHashSet::ConstructorJUHSIF;
    sElaHashSetCallback.elastos_HashSet_ConstructorJUHS_JUC = &AwHashSet::ConstructorJUHSJUC;

    Elastos_HashSet_InitCallback((Handle32)&sElaHashSetCallback);
    return &sElaHashSetCallback;
}

static void* sPElaHashSetCallback = AwHashSet::ElaHashSetCallback_Init();

} // namespace Api
} // namespace Webkit
} // namespace Droid
} // namespace Elastos

#endif //ELASTOS_HASHSET_CALLBACK_DEC_HH
