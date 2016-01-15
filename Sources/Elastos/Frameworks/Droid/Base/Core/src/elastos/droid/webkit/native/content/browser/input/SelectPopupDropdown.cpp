
#include "elastos/droid/webkit/native/content/browser/input/SelectPopupDropdown.h"
#include "elastos/droid/webkit/native/content/browser/ContentViewCore.h"
#include "elastos/droid/webkit/native/ui/DropdownPopupWindow.h"
#include "elastos/droid/webkit/native/ui/DropdownAdapter.h"
#include "elastos/droid/webkit/native/ui/DropdownItem.h"

using Elastos::Droid::Webkit::Ui::DropdownAdapter;
using Elastos::Droid::Webkit::Ui::DropdownItem;
using Elastos::Droid::Widget::EIID_IAdapterViewOnItemClickListener;
using Elastos::Droid::Widget::EIID_IPopupWindowOnDismissListener;
using Elastos::Droid::Widget::EIID_IListAdapter;
using Elastos::Droid::Widget::IListAdapter;

namespace Elastos {
namespace Droid {
namespace Webkit {
namespace Content {
namespace Browser {
namespace Input {

//==================================================================
//    SelectPopupDropdown::InnerAdapterViewOnItemClickListener
//==================================================================

CAR_INTERFACE_IMPL(SelectPopupDropdown::InnerAdapterViewOnItemClickListener, Object, IAdapterViewOnItemClickListener);

SelectPopupDropdown::InnerAdapterViewOnItemClickListener::InnerAdapterViewOnItemClickListener(
    /* [in] */ SelectPopupDropdown* owner)
    : mOwner(owner)
{
}

ECode SelectPopupDropdown::InnerAdapterViewOnItemClickListener::OnItemClick(
    /* [in] */ IAdapterView* parent,
    /* [in] */ IView* view,
    /* [in] */ Int32 position,
    /* [in] */ Int64 id)
{
    AutoPtr< ArrayOf<Int32> > selectedIndices = ArrayOf<Int32>::Alloc(1);
    (*selectedIndices)[0] = position;
    mOwner->mContentViewCore->SelectPopupMenuItems(selectedIndices);
    mOwner->mAlreadySelectedItems = TRUE;
    mOwner->Hide();

    return NOERROR;
}

//==================================================================
//     SelectPopupDropdown::InnerPopupWindowOnDismissListener
//==================================================================

CAR_INTERFACE_IMPL(SelectPopupDropdown::InnerPopupWindowOnDismissListener, Object, IPopupWindowOnDismissListener);

SelectPopupDropdown::InnerPopupWindowOnDismissListener::InnerPopupWindowOnDismissListener(
    /* [in] */ SelectPopupDropdown* owner)
    : mOwner(owner)
{
}

ECode SelectPopupDropdown::InnerPopupWindowOnDismissListener::OnDismiss()
{
    if (!mOwner->mAlreadySelectedItems) {
        mOwner->mContentViewCore->SelectPopupMenuItems(NULL);
    }

    return NOERROR;
}

//==================================================================
//                     SelectPopupDropdown
//==================================================================

SelectPopupDropdown::SelectPopupDropdown(
    /* [in] */ ContentViewCore* contentViewCore,
    /* [in] */ IList* items,
    /* [in] */ IRect* bounds,
    /* [in] */ ArrayOf<Int32>* selected)
    : mInitialSelection(-1)
    , mAlreadySelectedItems(FALSE)
{
    mContentViewCore = contentViewCore;
    mContext = mContentViewCore->GetContext();
    mDropdownPopupWindow = new DropdownPopupWindow(mContext,
            mContentViewCore->GetViewAndroidDelegate());
    AutoPtr<IAdapterViewOnItemClickListener> clickListener =  new InnerAdapterViewOnItemClickListener(this);
    assert(0);
    // TODO
    // mDropdownPopupWindow->SetOnItemClickListener(clickListener);
    if (selected->GetLength() > 0) {
        mInitialSelection = (*selected)[0];
    }

    assert(0);
    // TODO
    // AutoPtr< ArrayOf<DropdownItem*> > dropdownItems;
    // Int32 size;
    // items->GetSize(&size);
    // AutoPtr< ArrayOf<DropdownItem*> > list = ArrayOf<DropdownItem*>::Alloc(size);
    // items->ToArray(list, (ArrayOf<DropdownItem*>**)&dropdownItems);
    // AutoPtr<DropdownAdapter> adapter = new DropdownAdapter(mContext, dropdownItems, NULL);
    AutoPtr<IListAdapter> listView;
    assert(0);
    // TODO
    // listView = IListAdapter::Probe(adapter);
    mDropdownPopupWindow->SetAdapter(listView);
    AutoPtr<RenderCoordinates> renderCoordinates = mContentViewCore->GetRenderCoordinates();
    Int32 left;
    bounds->GetLeft(&left);
    Float anchorX = renderCoordinates->FromPixToDip(
            renderCoordinates->FromLocalCssToPix(left));
    Int32 top;
    bounds->GetTop(&top);
    Float anchorY = renderCoordinates->FromPixToDip(
            renderCoordinates->FromLocalCssToPix(top));
    Int32 right;
    bounds->GetRight(&right);
    Float anchorWidth = renderCoordinates->FromPixToDip(
            renderCoordinates->FromLocalCssToPix(right)) - anchorX;
    Int32 bottom;
    bounds->GetBottom(&bottom);
    Float anchorHeight = renderCoordinates->FromPixToDip(
            renderCoordinates->FromLocalCssToPix(bottom)) - anchorY;
    mDropdownPopupWindow->SetAnchorRect(anchorX, anchorY, anchorWidth, anchorHeight);
    AutoPtr<IPopupWindowOnDismissListener> dismissListener = new InnerPopupWindowOnDismissListener(this);
    mDropdownPopupWindow->SetOnDismissListener(dismissListener);
}

//@Override
void SelectPopupDropdown::Show()
{
    mDropdownPopupWindow->Show();
    if (mInitialSelection >= 0) {
        assert(0);
        // TODO
        // mDropdownPopupWindow->GetListView()->SetSelection(mInitialSelection);
    }
}

//@Override
void SelectPopupDropdown::Hide()
{
    assert(0);
    // TODO
    // mDropdownPopupWindow->Dismiss();
}

} // namespace Input
} // namespace Browser
} // namespace Content
} // namespace Webkit
} // namespace Droid
} // namespace Elastos
