// Copyright (c) Borislav Stanimirov
// SPDX-License-Identifier: MIT
//
#pragma once

// macros to enable and disable warnings

#if defined(_MSC_VER)
#   define PRAGMA_WARNING_PUSH __pragma(warning(push))
#   define PRAGMA_WARNING_POP  __pragma(warning(pop))
#   define DISABLE_MSVC_WARNING(w) __pragma(warning(disable : w))
#   define DISABLE_GCC_ONLY_WARNING(w)
#   define DISABLE_CLANG_ONLY_WARNING(w)
#   define DISABLE_GCC_AND_CLANG_WARNING(w)
#elif defined(__GNUC__) // also defined by clang
#   define PRAGMA_WARNING_PUSH _Pragma("GCC diagnostic push")
#   define PRAGMA_WARNING_POP  _Pragma("GCC diagnostic pop")
#   define DISABLE_MSVC_WARNING(w)
#   define I_SPLAT_PRAGMA(x) _Pragma(#x)
#   define DISABLE_GCC_AND_CLANG_WARNING(w) I_SPLAT_PRAGMA(GCC diagnostic ignored w)
#   if defined(__clang__)
#       define DISABLE_GCC_ONLY_WARNING(w)
#       define DISABLE_CLANG_ONLY_WARNING(w) I_SPLAT_PRAGMA(GCC diagnostic ignored w)
#   else
#       define DISABLE_GCC_ONLY_WARNING(w) I_SPLAT_PRAGMA(GCC diagnostic ignored w)
#       define DISABLE_CLANG_ONLY_WARNING(w)
#   endif
#else
#   define PRAGMA_WARNING_PUSH
#   define PRAGMA_WARNING_POP
#   define DISABLE_MSVC_WARNING(w)
#   define DISABLE_GCC_ONLY_WARNING(w)
#   define DISABLE_CLANG_ONLY_WARNING(w)
#   define DISABLE_GCC_AND_CLANG_WARNING(w)
#endif
