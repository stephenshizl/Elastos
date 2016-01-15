#include "elastos/droid/ext/frameworkdef.h"
#include "CActivityOne.h"
#include <stdio.h>
#include "R.h"

namespace Elastos {
namespace Droid {
namespace DevSamples {
namespace TableLayoutDemo {

CAR_INTERFACE_IMPL(MyListener, IViewOnClickListener)

MyListener::MyListener(
    /* [in] */ CActivityOne* host)
{
    mHost = host;
}

ECode MyListener::OnClick(
   /* [in] */ IView* v)
{
    printf("The Button in TableLayout was Clicked");
    return NOERROR;
}

ECode CActivityOne::OnCreate(
    /* [in] */ IBundle* savedInstanceState)
{
    Activity::OnCreate(savedInstanceState);
    PRINT_ENTER_LEAVE("CActivityOne::OnCreate");
    SetContentView(R::layout::main);
    return NOERROR;
}

ECode CActivityOne::OnStart()
{
    PRINT_ENTER_LEAVE("CActivityOne::OnStart");
    // TODO: Add your code here
    return NOERROR;
}

ECode CActivityOne::OnResume()
{
    PRINT_ENTER_LEAVE("CActivityOne::OnResume");
    // TODO: Add your code here
    return NOERROR;
}

ECode CActivityOne::OnPause()
{
    PRINT_ENTER_LEAVE("CActivityOne::OnPause");
    // TODO: Add your code here
    return NOERROR;
}

ECode CActivityOne::OnStop()
{
    PRINT_ENTER_LEAVE("OnStop");
    // TODO: Add your code here
    return NOERROR;
}

ECode CActivityOne::OnDestroy()
{
    PRINT_ENTER_LEAVE("OnDestroy");
    // TODO: Add your code here
    return NOERROR;
}

ECode CActivityOne::OnActivityResult(
    /* [in] */ Int32 requestCode,
    /* [in] */ Int32 resultCode,
    /* [in] */ IIntent *data)
{
    PRINT_ENTER_LEAVE("OnActivityResult");
    return NOERROR;
}

} // namespace TableLayoutDemo
} // namespace DevSamples
} // namespace Droid
} // namespace Elastos
