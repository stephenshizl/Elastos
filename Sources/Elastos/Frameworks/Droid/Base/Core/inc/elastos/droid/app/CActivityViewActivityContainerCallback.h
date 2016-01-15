
#ifndef __ELASTOS_DROID_APP_CACTIVITY_VIEW_ACTIVITY_CONTAINER_CALLBACK_H__
#define __ELASTOS_DROID_APP_CACTIVITY_VIEW_ACTIVITY_CONTAINER_CALLBACK_H__

#include "_Elastos_Droid_App_CActivityViewActivityContainerCallback.h"
#include "elastos/droid/app/ActivityView.h"

namespace Elastos {
namespace Droid {
namespace App {

CarClass(CActivityViewActivityContainerCallback)
    , public ActivityView::ActivityContainerCallback
{
public:
    CAR_OBJECT_DECL()
};

} // namespace App
} // namespace Droid
} // namespace Elastos

#endif //__ELASTOS_DROID_APP_CACTIVITY_VIEW_ACTIVITY_CONTAINER_CALLBACK_H__