// Copyright (c) Borislav Stanimirov
// SPDX-License-Identifier: MIT
//
#pragma once

// determine host byte order (big or little-endian) at compile-time
// error on unknown or exotic architectures like PDP or Honeywell (endian-X-word)

// prefer the compiler builtin __BYTE_ORDER__ (GCC >= 4.6, Clang)
#if defined(__BYTE_ORDER__) && defined(__ORDER_BIG_ENDIAN__) && defined(__ORDER_LITTLE_ENDIAN__)
#   if __BYTE_ORDER__ == __ORDER_BIG_ENDIAN__
#       define I_SPLAT_HOST_IS_BIG_ENDIAN 1
#   elif __BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__
#       define I_SPLAT_HOST_IS_BIG_ENDIAN 0
    // __ORDER_PDP_ENDIAN__ or anything else: leave undefined -> #error
#   endif
#elif defined(_WIN32)
// Windows did support PowerPC, but that's ancient. No need to check this in 2026
#   if defined(__ARMEB__) || defined(__THUMBEB__) || defined(__AARCH64EB__)
#       define I_SPLAT_HOST_IS_BIG_ENDIAN 1
#   elif defined(_M_IX86) || defined(_M_X64) || defined(_M_AMD64) || \
         defined(_M_ARM)  || defined(_M_ARM64) || defined(_M_IA64) || \
         defined(__i386__) || defined(__x86_64__) || \
         defined(__arm__)  || defined(__aarch64__)
#       define I_SPLAT_HOST_IS_BIG_ENDIAN 0
#   endif
// non-windows non-gcc/clang: we have to resort to an endian header
#elif defined(__linux__) || defined(__CYGWIN__)
#   include <endian.h>
#   if __BYTE_ORDER == __BIG_ENDIAN
#       define I_SPLAT_HOST_IS_BIG_ENDIAN 1
#   elif __BYTE_ORDER == __LITTLE_ENDIAN
#       define I_SPLAT_HOST_IS_BIG_ENDIAN 0
#   endif
#else
#   if defined(__APPLE__)
#       include <libkern/OSByteOrder.h>
#   elif defined(__FreeBSD__) || defined(__NetBSD__) || defined(__OpenBSD__) || defind(__DragonFly__)
#       include <sys/endian.h>
#   else
#       error "Unknown platform: cannot locate an endianness header"
#   endif

#   if BYTE_ORDER == BIG_ENDIAN
#       define I_SPLAT_HOST_IS_BIG_ENDIAN 1
#   elif BYTE_ORDER == LITTLE_ENDIAN
#       define I_SPLAT_HOST_IS_BIG_ENDIAN 0
#   endif
#endif

#if !defined(I_SPLAT_HOST_IS_BIG_ENDIAN)
#   error "Could not determine host endianness"
#elif I_SPLAT_HOST_IS_BIG_ENDIAN
#   define BIG_ENDIAN_HOST 1
#   define HOST_IS_BIG_ENDIAN 1
#   define HOST_IS_LITTLE_ENDIAN 0
#else
#   define LITTLE_ENDIAN_HOST 1
#   define HOST_IS_BIG_ENDIAN 0
#   define HOST_IS_LITTLE_ENDIAN 1
#endif
