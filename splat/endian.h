// Copyright (c) Borislav Stanimirov
// SPDX-License-Identifier: MIT
//
#pragma once

// determine host byte order at compile-time

// no support for exotic architectures like PDP or Honeywell (endian-X-word)

// look for popular definitions
#if defined(__BYTE_ORDER) && __BYTE_ORDER == __BIG_ENDIAN || \
    defined(__BIG_ENDIAN__) || \
    defined(__ARMEB__) || \
    defined(__THUMBEB__) || \
    defined(__AARCH64EB__) || \
    defined(_MIBSEB) || defined(__MIBSEB) || defined(__MIBSEB__)
#define BIG_ENDIAN_HOST 1
#define HOST_IS_BIG_ENDIAN 1
#define HOST_IS_LITTLE_ENDIAN 0
#else
// default to LE
#define LITTLE_ENDIAN_HOST 1
#define HOST_IS_BIG_ENDIAN 0
#define HOST_IS_LITTLE_ENDIAN 1
#endif
