//=========================================================================
// Copyright (C) 2012 The Elastos Open Source Project
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//      http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//=========================================================================

#include "Elastos.Droid.Google.h"
#include "elastos/droid/google/mms/pdu/ReadOrigInd.h"

namespace Elastos {
namespace Droid {
namespace Google {
namespace Mms {
namespace Pdu {

//=====================================================================
//                             ReadOrigInd
//=====================================================================
CAR_INTERFACE_IMPL(ReadOrigInd, GenericPdu, IReadOrigInd);

ReadOrigInd::ReadOrigInd()
{
    constructor();
}

ECode ReadOrigInd::constructor()
{
    GenericPdu::constructor();
    SetMessageType(IPduHeaders::MESSAGE_TYPE_READ_ORIG_IND);
    return NOERROR;
}

ECode ReadOrigInd::constructor(
    /* [in] */ IPduHeaders* headers)
{
    GenericPdu::constructor(headers);
    return NOERROR;
}

ECode ReadOrigInd::GetDate(
    /* [out] */ Int64* result)
{
    VALIDATE_NOT_NULL(result);
    return mPduHeaders->GetLongInteger(IPduHeaders::DATE, result);
}

ECode ReadOrigInd::SetDate(
    /* [in] */ Int64 value)
{
    mPduHeaders->SetLongInteger(value, IPduHeaders::DATE);
    return NOERROR;
}

ECode ReadOrigInd::GetFrom(
    /* [out] */ IEncodedStringValue** result)
{
    VALIDATE_NOT_NULL(result);
    return mPduHeaders->GetEncodedStringValue(IPduHeaders::FROM, result);
}

ECode ReadOrigInd::SetFrom(
    /* [in] */ IEncodedStringValue* value)
{
    VALIDATE_NOT_NULL(value);
    mPduHeaders->SetEncodedStringValue(value, IPduHeaders::FROM);
    return NOERROR;
}

ECode ReadOrigInd::GetMessageId(
    /* [out] */ ArrayOf<Byte>** result)
{
    VALIDATE_NOT_NULL(result);
    return mPduHeaders->GetTextString(IPduHeaders::MESSAGE_ID, result);
}

ECode ReadOrigInd::SetMessageId(
    /* [in] */ ArrayOf<Byte>* value)
{
    VALIDATE_NOT_NULL(value);
    mPduHeaders->SetTextString(value, IPduHeaders::MESSAGE_ID);
    return NOERROR;
}

ECode ReadOrigInd::GetReadStatus(
    /* [out] */ Int32* result)
{
    VALIDATE_NOT_NULL(result);
    return mPduHeaders->GetOctet(IPduHeaders::READ_STATUS, result);
}

ECode ReadOrigInd::SetReadStatus(
    /* [in] */ Int32 value)
{
    mPduHeaders->SetOctet(value, IPduHeaders::READ_STATUS);
    return NOERROR;
}

ECode ReadOrigInd::GetTo(
    /* [out] */ ArrayOf<IEncodedStringValue*>** result)
{
    VALIDATE_NOT_NULL(result);
    return mPduHeaders->GetEncodedStringValues(IPduHeaders::TO, result);
}

ECode ReadOrigInd::SetTo(
    /* [in] */ ArrayOf<IEncodedStringValue*>* value)
{
    VALIDATE_NOT_NULL(value);
    mPduHeaders->SetEncodedStringValues(value, IPduHeaders::TO);
    return NOERROR;
}

} // namespace Pdu
} // namespace Mms
} // namespace Google
} // namespace Droid
} // namespace Elastos
