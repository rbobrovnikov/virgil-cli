/**
 * Copyright (C) 2015-2017 Virgil Security Inc.
 *
 * Lead Maintainer: Virgil Security Inc. <support@virgilsecurity.com>
 *
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are
 * met:
 *
 *     (1) Redistributions of source code must retain the above copyright
 *     notice, this list of conditions and the following disclaimer.
 *
 *     (2) Redistributions in binary form must reproduce the above copyright
 *     notice, this list of conditions and the following disclaimer in
 *     the documentation and/or other materials provided with the
 *     distribution.
 *
 *     (3) Neither the name of the copyright holder nor the names of its
 *     contributors may be used to endorse or promote products derived from
 *     this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ''AS IS'' AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT,
 * INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
 * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING
 * IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

#include <cli/model/SecureValue.h>

using cli::Crypto;
using cli::model::SecureValue;

static void zeroize(Crypto::Text& text) {
    for (volatile auto& symbol : text) {
        symbol = '\0';
    }
}

static void zeroize(Crypto::Bytes& bytes) {
    for (volatile auto& symbol : bytes) {
        symbol = 0x00;
    }
}

SecureValue::SecureValue() {}

SecureValue::SecureValue(Crypto::Bytes value)
        : stringValue_(Crypto::ByteUtils::bytesToString(value)), bytesValue_(std::move(value))  {
}

SecureValue::SecureValue(Crypto::Text value)
        : stringValue_(std::move(value)), bytesValue_(Crypto::ByteUtils::stringToBytes(stringValue_))  {
}

SecureValue::~SecureValue() noexcept {
    zeroize(bytesValue_);
    zeroize(stringValue_);
}

const Crypto::Text& SecureValue::stringValue() const {
    return stringValue_;
}

const Crypto::Bytes& SecureValue::bytesValue() const {
    return bytesValue_;
}
