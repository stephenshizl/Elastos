
#include "elastos/droid/webkit/native/content/browser/PowerSaveBlocker.h"
#include "elastos/droid/webkit/native/content/api/PowerSaveBlocker_dec.h"
#include "elastos/droid/webkit/native/ui/base/ViewElastos.h"

using Elastos::Droid::Webkit::Ui::Base::ViewElastos;

namespace Elastos {
namespace Droid {
namespace Webkit {
namespace Content {
namespace Browser {

//=====================================================================
//                           PowerSaveBlocker
//=====================================================================

ECode PowerSaveBlocker::ApplyBlock(
    /* [in] */ ViewElastos* view)
{
    return view->IncrementKeepScreenOnCount();
}

ECode PowerSaveBlocker::RemoveBlock(
    /* [in] */ ViewElastos* view)
{
    return view->DecrementKeepScreenOnCount();
}

void PowerSaveBlocker::ApplyBlock(
    /* [in] */ IInterface* view)
{
    AutoPtr<ViewElastos> ve = (ViewElastos*)(IObject::Probe(view));
    ApplyBlock(ve);
}

void PowerSaveBlocker::RemoveBlock(
    /* [in] */ IInterface* view)
{
    AutoPtr<ViewElastos> ve = (ViewElastos*)(IObject::Probe(view));
    RemoveBlock(ve);
}

} // namespace Browser
} // namespace Content
} // namespace Webkit
} // namespace Droid
} // namespace Elastos
