// Copyright (c) 2012, Cornell University
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are met:
//
//     * Redistributions of source code must retain the above copyright notice,
//       this list of conditions and the following disclaimer.
//     * Redistributions in binary form must reproduce the above copyright
//       notice, this list of conditions and the following disclaimer in the
//       documentation and/or other materials provided with the distribution.
//     * Neither the name of HyperDex nor the names of its contributors may be
//       used to endorse or promote products derived from this software without
//       specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
// AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
// ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
// LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
// CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
// SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
// INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
// CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
// ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
// POSSIBILITY OF SUCH DAMAGE.

#ifndef hyperdex_coordinator_util_h_
#define hyperdex_coordinator_util_h_

// e
#include <e/endian.h>

// Replicant
#include <replicant_state_machine.h>

// HyperDex
#include "common/coordinator_returncode.h"
#include "coordinator/coordinator.h"

#define PROTECT_UNINITIALIZED \
    do \
    { \
        if (!obj) \
        { \
            fprintf(replicant_state_machine_log_stream(ctx), "cannot operate on NULL object"); \
            replicant_state_machine_set_response(ctx, "", 0); \
            return; \
        } \
    } \
    while (0)

namespace hyperdex
{

inline void
generate_response(replicant_state_machine_context* ctx, coordinator* c, coordinator_returncode x)
{
    e::pack16be(static_cast<uint16_t>(x), c->resp);
    replicant_state_machine_set_response(ctx, c->resp, sizeof(uint16_t));
}

} // namespace hyperdex

#endif // hyperdex_coordinator_util_h_
