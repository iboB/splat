// Copyright (c) Borislav Stanimirov
// SPDX-License-Identifier: MIT
//
#pragma once

#define SPLAT_PP_EMPTY()

#define SPLAT_PP_CAT(a, b) SPLAT_PP_INTERNAL_CAT(a, b)
#define SPLAT_PP_INTERNAL_CAT(a, b) a##b

#define SPLAT_PP_STRINGIZE(x) #x
