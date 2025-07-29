// Copyright (c) Borislav Stanimirov
// SPDX-License-Identifier: MIT
//
#pragma once

// unreachable macro

#if defined(_MSC_VER)
#   define SPLAT_UNREACHABLE() __assume(false)
#else
#   define SPLAT_UNREACHABLE() __builtin_unreachable()
#endif
