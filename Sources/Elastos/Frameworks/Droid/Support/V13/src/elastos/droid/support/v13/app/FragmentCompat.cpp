
#include "elastos/droid/support/v13/app/FragmentCompat.h"
#include "elastos/droid/support/v13/app/FragmentCompatICS.h"
#include "elastos/droid/support/v13/app/FragmentCompatICSMR1.h"
#include "elastos/droid/os/Build.h"

using Elastos::Droid::Os::Build;
using Elastos::Droid::Support::V13::App::EIID_IFragmentCompatImpl;

namespace Elastos {
namespace Droid {
namespace Support {
namespace V13 {
namespace App {

//==========================================================
// FragmentCompat::BaseFragmentCompatImpl
//==========================================================
CAR_INTERFACE_IMPL(FragmentCompat::BaseFragmentCompatImpl, Object, IFragmentCompatImpl)

ECode FragmentCompat::BaseFragmentCompatImpl::SetMenuVisibility(
    /* [in] */ IFragment* f,
    /* [in] */ Boolean visible)
{
    return NOERROR;
}

ECode FragmentCompat::BaseFragmentCompatImpl::SetUserVisibleHint(
    /* [in] */ IFragment* f,
    /* [in] */ Boolean deferStart)
{
    return NOERROR;
}


//==========================================================
// FragmentCompat::ICSFragmentCompatImpl
//==========================================================
ECode FragmentCompat::ICSFragmentCompatImpl::SetMenuVisibility(
    /* [in] */ IFragment* f,
    /* [in] */ Boolean visible)
{
    FragmentCompatICS::SetMenuVisibility(f, visible);
    return NOERROR;
}


//==========================================================
// FragmentCompat::ICSMR1FragmentCompatImpl
//==========================================================
ECode FragmentCompat::ICSMR1FragmentCompatImpl::SetUserVisibleHint(
    /* [in] */ IFragment* f,
    /* [in] */ Boolean visible)
{
    FragmentCompatICSMR1::SetUserVisibleHint(f, visible);
    return NOERROR;
}


//==========================================================
// FragmentCompat::StaticInitializer
//==========================================================
FragmentCompat::StaticInitializer::StaticInitializer()
{
    if (Build::VERSION::SDK_INT >= 15) {
        IMPL = (IFragmentCompatImpl*)new ICSMR1FragmentCompatImpl();
    }
    else if (Build::VERSION::SDK_INT >= 14) {
        IMPL = (IFragmentCompatImpl*)new ICSFragmentCompatImpl();
    }
    else {
        IMPL = (IFragmentCompatImpl*)new BaseFragmentCompatImpl();
    }
}


//==========================================================
// FragmentCompat
//==========================================================
AutoPtr<IFragmentCompatImpl> FragmentCompat::IMPL;
FragmentCompat::StaticInitializer FragmentCompat::sInitializer;

void FragmentCompat::SetMenuVisibility(
    /* [in] */ IFragment* f,
    /* [in] */ Boolean visible)
{
    IMPL->SetMenuVisibility(f, visible);
}

void FragmentCompat::SetUserVisibleHint(
    /* [in] */ IFragment* f,
    /* [in] */ Boolean visible)
{
    IMPL->SetUserVisibleHint(f, visible);
}

} // namespace App
} // namespace V13
} // namespace Support
} // namespace Droid
} // namespace Elastos
