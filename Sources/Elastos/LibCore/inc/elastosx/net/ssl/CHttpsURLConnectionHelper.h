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

#ifndef __ELASTOSX_NET_SSL_CHTTPSURLCONNECTIONHELPER_H__
#define __ELASTOSX_NET_SSL_CHTTPSURLCONNECTIONHELPER_H__

#include "_Elastosx_Net_Ssl_CHttpsURLConnectionHelper.h"
#include "elastos/core/Singleton.h"

using Elastosx::Net::Ssl::ISSLSocketFactory;
using Elastosx::Net::Ssl::IHostnameVerifier;

namespace Elastosx {
namespace Net {
namespace Ssl {

CarClass(CHttpsURLConnectionHelper)
    , public Singleton
    , public IHttpsURLConnectionHelper
{
public:
    CAR_INTERFACE_DECL()

    CAR_SINGLETON_DECL()

    /**
     * Sets the default hostname verifier to be used by new instances.
     *
     * @param v
     *            the new default hostname verifier
     * @throws IllegalArgumentException
     *             if the specified verifier is {@code null}.
     */
    CARAPI SetDefaultHostnameVerifier(
        /* [in] */ IHostnameVerifier* v);

    /**
     * Returns the default hostname verifier.
     *
     * @return the default hostname verifier.
     */
    CARAPI GetDefaultHostnameVerifier(
        /* [out] */ IHostnameVerifier** verifier);

    /**
     * Sets the default SSL socket factory to be used by new instances.
     *
     * @param sf
     *            the new default SSL socket factory.
     * @throws IllegalArgumentException
     *             if the specified socket factory is {@code null}.
     */
    CARAPI SetDefaultSSLSocketFactory(
        /* [in] */ ISSLSocketFactory* sf);

    /**
     * Returns the default SSL socket factory for new instances.
     *
     * @return the default SSL socket factory for new instances.
     */
    CARAPI GetDefaultSSLSocketFactory(
        /* [out] */ ISSLSocketFactory** factory);
};

} // namespace Ssl
} // namespace Net
} // namespace Elastosx

#endif //__ELASTOSX_NET_SSL_CHTTPSURLCONNECTIONHELPER_H__
