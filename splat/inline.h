// Copyright (c) Borislav Stanimirov
// SPDX-License-Identifier: MIT
//
#pragma once

// macros to force inlining or no-inlining of functions

#if !defined(FORCE_INLINE)
#   if defined(__GNUC__)
#       define FORCE_INLINE __attribute__((always_inline)) inline
#   elif defined(_MSC_VER)
#       define FORCE_INLINE  __forceinline
#   else
#       define FORCE_INLINE  inline
#   endif
#endif

#if !defined(NOINLINE)
#   if defined(_MSC_VER)
#       define NOINLINE __declspec(noinline)
#   else
#       define NOINLINE __attribute__((noinline))
#   endif
#endif

#if defined(__cplusplus) && !defined(FORCE_INLINE_LAMBDA)
#   if defined(__GNUC__)
#       define FORCE_INLINE_LAMBDA __attribute__((always_inline))
#   elif defined(_MSC_VER)
#       define FORCE_INLINE_LAMBDA  [[msvc::forceinline]]
#   else
#       define FORCE_INLINE_LAMBDA
#   endif
#endif
