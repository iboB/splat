// Copyright (c) Borislav Stanimirov
// SPDX-License-Identifier: MIT
//
#pragma once

// macro to force inlining of functions

#if defined(__GNUC__)
#   define FORCE_INLINE __attribute__((always_inline))
#elif defined(_MSC_VER)
#   define FORCE_INLINE  __forceinline
#else
#   define FORCE_INLINE  inline
#endif
