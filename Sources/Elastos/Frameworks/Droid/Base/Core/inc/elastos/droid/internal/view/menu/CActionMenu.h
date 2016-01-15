#ifndef __ELASTOS_DROID_INTERNAL_VIEW_MENU_CACTIONMENU_H__
#define __ELASTOS_DROID_INTERNAL_VIEW_MENU_CACTIONMENU_H__

#include "_Elastos_Droid_Internal_View_Menu_CActionMenu.h"
#include "elastos/droid/internal/view/menu/ActionMenu.h"

namespace Elastos {
namespace Droid {
namespace Internal {
namespace View {
namespace Menu {

CarClass(CActionMenu)
    , public ActionMenu
{
public:
    CAR_OBJECT_DECL()
};

} // namespace Menu
} // namespace View
} // namespace Internal
} // namespace Droid
} // namespace Elastos

#endif //__ELASTOS_DROID_INTERNAL_VIEW_MENU_CACTIONMENU_H__
