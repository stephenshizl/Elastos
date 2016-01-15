
#ifndef __ELASTOS_DROID_INTERNAL_APP_CDISABLECARMODEACTIVITY_H__
#define __ELASTOS_DROID_INTERNAL_APP_CDISABLECARMODEACTIVITY_H__

#include "_Elastos_Droid_Internal_App_CDisableCarModeActivity.h"
#include "elastos/droid/internal/app/DisableCarModeActivity.h"

namespace Elastos {
namespace Droid {
namespace Internal {
namespace App {

CarClass(CDisableCarModeActivity)
    , public DisableCarModeActivity
{
public:
    CAR_OBJECT_DECL()
};

} //namespace App
} //namespace Internal
} //namespace Droid
} //namespace Elastos

#endif //__ELASTOS_DROID_INTERNAL_APP_CDISABLECARMODEACTIVITY_H__
