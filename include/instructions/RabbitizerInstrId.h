/* SPDX-FileCopyrightText: © 2022 Decompollaborate */
/* SPDX-License-Identifier: MIT */

#ifndef RABBITIZER_INSTRID_H
#define RABBITIZER_INSTRID_H
#pragma once

#include "common/Utils.h"


#define RABBITIZER_DEF_INSTR_ID(prefix, caseBits, name, ...) \
    RABBITIZER_INSTR_ID_##prefix##_##name,

#define RABBITIZER_DEF_INSTR_ID_ALTNAME(prefix, caseBits, name, altname, ...) \
    RABBITIZER_DEF_INSTR_ID(prefix, caseBits, name, __VA_ARGS__)

typedef enum RabbitizerInstrId {
    #include "instructions/instr_id/RabbitizerInstrId_cpu.inc"

    #include "instructions/instr_id/RabbitizerInstrId_rsp.inc"
    RABBITIZER_DEF_INSTR_ID(rsp, , MAX, )

    RABBITIZER_INSTR_ID_ALL_MAX = RABBITIZER_DEF_INSTR_ID(rsp, , MAX, )
} RabbitizerInstrId;

#undef RABBITIZER_DEF_INSTR_ID
#undef RABBITIZER_DEF_INSTR_ID_ALTNAME


extern const char *RabbitizerInstrId_Names[];


CONST NODISCARD RETURNS_NON_NULL
const char *RabbitizerInstrId_getOpcodeName(RabbitizerInstrId uniqueId);

#endif
