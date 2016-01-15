
#ifndef __ELASTOS_DROID_TEXT_STYLE_CSTRIKETHROUGHSPAN_H__
#define __ELASTOS_DROID_TEXT_STYLE_CSTRIKETHROUGHSPAN_H__

#include "_Elastos_Droid_Text_Style_CStrikethroughSpan.h"
#include "elastos/droid/text/style/StrikethroughSpan.h"

namespace Elastos {
namespace Droid {
namespace Text {
namespace Style {

CarClass(CStrikethroughSpan)
    , public StrikethroughSpan
{
public:
    CAR_OBJECT_DECL()
};

} // namespace Style
} // namespace Text
} // namepsace Droid
} // namespace Elastos

#endif // __ELASTOS_DROID_TEXT_STYLE_CSTRIKETHROUGHSPAN_H__
