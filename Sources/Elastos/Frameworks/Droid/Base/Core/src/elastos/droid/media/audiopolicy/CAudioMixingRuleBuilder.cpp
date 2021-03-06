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

#include <Elastos.CoreLibrary.Utility.h>
#include "elastos/droid/media/audiopolicy/CAudioMixingRuleBuilder.h"
#include "elastos/droid/media/audiopolicy/CAudioMixingRule.h"
#include <elastos/core/AutoLock.h>

#include <elastos/core/AutoLock.h>
using Elastos::Core::AutoLock;
using Elastos::Core::AutoLock;
using Elastos::Utility::CArrayList;
using Elastos::Utility::IIterator;
using Elastos::Droid::Media::AudioPolicy::CAudioMixingRule;

namespace Elastos {
namespace Droid {
namespace Media {
namespace AudioPolicy {

CAR_INTERFACE_IMPL(CAudioMixingRuleBuilder, Object, IAudioMixingRuleBuilder)

CAR_OBJECT_IMPL(CAudioMixingRuleBuilder)

CAudioMixingRuleBuilder::CAudioMixingRuleBuilder()
{
}

CAudioMixingRuleBuilder::~CAudioMixingRuleBuilder()
{
}

ECode CAudioMixingRuleBuilder::constructor()
{
    return CArrayList::New((IArrayList**)&mCriteria);
}

ECode CAudioMixingRuleBuilder::AddRule(
    /* [in] */ IAudioAttributes * attrToMatch,
    /* [in] */ Int32 rule,
    /* [out] */ IAudioMixingRuleBuilder** builder)
{
    VALIDATE_NOT_NULL(builder)
    *builder = NULL;
    if (attrToMatch == NULL) {
        // throw new IllegalArgumentException("Illegal null AudioAttributes argument");
        return E_ILLEGAL_ARGUMENT_EXCEPTION;
    }
    if ((rule != IAudioMixingRule::RULE_MATCH_ATTRIBUTE_USAGE)
            && (rule != IAudioMixingRule::RULE_EXCLUDE_ATTRIBUTE_USAGE)) {
        // throw new IllegalArgumentException("Illegal rule value " + rule);
        return E_ILLEGAL_ARGUMENT_EXCEPTION;
    }
    {    AutoLock syncLock(mCriteria);
        AutoPtr<IIterator> crIterator;
        mCriteria->GetIterator((IIterator**)&crIterator);
        Boolean b;
        crIterator->HasNext(&b);
        while (b) {
            AutoPtr<IInterface> obj;
            crIterator->GetNext((IInterface**)&obj);
            AutoPtr<CAudioMixingRule::AttributeMatchCriterion> criterion =
                    (CAudioMixingRule::AttributeMatchCriterion*)IObject::Probe(obj);
            if ((rule == IAudioMixingRule::RULE_MATCH_ATTRIBUTE_USAGE)
                    || (rule == IAudioMixingRule::RULE_EXCLUDE_ATTRIBUTE_USAGE)) {
                // "usage"-based rule
                Int32 usage1, usage2;
                criterion->mAttr->GetUsage(&usage1);
                attrToMatch->GetUsage(&usage2);
                if (usage1 == usage2) {
                    if (criterion->mRule == rule) {
                        // rule already exists, we're done
                        *builder = this;
                        REFCOUNT_ADD(*builder)
                        return NOERROR;
                    } else {
                        // criterion already exists with a another rule, it is incompatible
                        // throw new IllegalArgumentException("Contradictory rule exists for "
                        //         + attrToMatch);
                        return E_ILLEGAL_ARGUMENT_EXCEPTION;
                    }
                }
            }
        }
        // rule didn't exist, add it
        AutoPtr<CAudioMixingRule::AttributeMatchCriterion> amc
            = new CAudioMixingRule::AttributeMatchCriterion(attrToMatch, rule);
        mCriteria->Add((IInterface*)(IObject*)amc);
    }
    *builder = this;
    REFCOUNT_ADD(*builder)
    return NOERROR;
}


ECode CAudioMixingRuleBuilder::Build(
    /* [out] */ IAudioMixingRule** result)
{
    return CAudioMixingRule::New(mCriteria, result);
}


} // namespace AudioPolicy
} // namespace Media
} // namepsace Droid
} // namespace Elastos
