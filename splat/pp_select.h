// Copyright (c) Borislav Stanimirov
// SPDX-License-Identifier: MIT
//
#pragma once

// generated by this ruby script:
/*
ARITY = 9
1.upto(ARITY + 1) do  |i|
  args = (1..i).map { "_#{_1}" }
  puts "#define SPLAT_SELECT_ARG_#{i}(#{args.join(', ')}, ...) #{args[-1]}"
end

puts "#define SPLAT_SELECTOR_TRAMPOLINE(SELECTOR, args) SELECTOR args"

VA_OPT = false
def va_opt_comma = VA_OPT ? '__VA_OPT__(,)' : ','

1.upto(ARITY) do |i|
  args = (0..i).map { "_a#{_1}" }
  puts "#define SPLAT_SELECT_ARITY_UPTO_#{i}(#{args.join(', ')}, ...) SPLAT_SELECTOR_TRAMPOLINE(SPLAT_SELECT_ARG_#{i+1}, (__VA_ARGS__ #{va_opt_comma} #{args.reverse.join(', ')}))(__VA_ARGS__)"
end
*/
// With C++20 the script can also generate __VA_OPT__ appropriately
// and allow us to support zero-arg selections
#define SPLAT_SELECT_ARG_1(_1, ...) _1
#define SPLAT_SELECT_ARG_2(_1, _2, ...) _2
#define SPLAT_SELECT_ARG_3(_1, _2, _3, ...) _3
#define SPLAT_SELECT_ARG_4(_1, _2, _3, _4, ...) _4
#define SPLAT_SELECT_ARG_5(_1, _2, _3, _4, _5, ...) _5
#define SPLAT_SELECT_ARG_6(_1, _2, _3, _4, _5, _6, ...) _6
#define SPLAT_SELECT_ARG_7(_1, _2, _3, _4, _5, _6, _7, ...) _7
#define SPLAT_SELECT_ARG_8(_1, _2, _3, _4, _5, _6, _7, _8, ...) _8
#define SPLAT_SELECT_ARG_9(_1, _2, _3, _4, _5, _6, _7, _8, _9, ...) _9
#define SPLAT_SELECT_ARG_10(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, ...) _10
#define SPLAT_SELECTOR_TRAMPOLINE(SELECTOR, args) SELECTOR args
#define SPLAT_SELECT_ARITY_UPTO_1(_a0, _a1, ...) SPLAT_SELECTOR_TRAMPOLINE(SPLAT_SELECT_ARG_2, (__VA_ARGS__ , _a1, _a0))(__VA_ARGS__)
#define SPLAT_SELECT_ARITY_UPTO_2(_a0, _a1, _a2, ...) SPLAT_SELECTOR_TRAMPOLINE(SPLAT_SELECT_ARG_3, (__VA_ARGS__ , _a2, _a1, _a0))(__VA_ARGS__)
#define SPLAT_SELECT_ARITY_UPTO_3(_a0, _a1, _a2, _a3, ...) SPLAT_SELECTOR_TRAMPOLINE(SPLAT_SELECT_ARG_4, (__VA_ARGS__ , _a3, _a2, _a1, _a0))(__VA_ARGS__)
#define SPLAT_SELECT_ARITY_UPTO_4(_a0, _a1, _a2, _a3, _a4, ...) SPLAT_SELECTOR_TRAMPOLINE(SPLAT_SELECT_ARG_5, (__VA_ARGS__ , _a4, _a3, _a2, _a1, _a0))(__VA_ARGS__)
#define SPLAT_SELECT_ARITY_UPTO_5(_a0, _a1, _a2, _a3, _a4, _a5, ...) SPLAT_SELECTOR_TRAMPOLINE(SPLAT_SELECT_ARG_6, (__VA_ARGS__ , _a5, _a4, _a3, _a2, _a1, _a0))(__VA_ARGS__)
#define SPLAT_SELECT_ARITY_UPTO_6(_a0, _a1, _a2, _a3, _a4, _a5, _a6, ...) SPLAT_SELECTOR_TRAMPOLINE(SPLAT_SELECT_ARG_7, (__VA_ARGS__ , _a6, _a5, _a4, _a3, _a2, _a1, _a0))(__VA_ARGS__)
#define SPLAT_SELECT_ARITY_UPTO_7(_a0, _a1, _a2, _a3, _a4, _a5, _a6, _a7, ...) SPLAT_SELECTOR_TRAMPOLINE(SPLAT_SELECT_ARG_8, (__VA_ARGS__ , _a7, _a6, _a5, _a4, _a3, _a2, _a1, _a0))(__VA_ARGS__)
#define SPLAT_SELECT_ARITY_UPTO_8(_a0, _a1, _a2, _a3, _a4, _a5, _a6, _a7, _a8, ...) SPLAT_SELECTOR_TRAMPOLINE(SPLAT_SELECT_ARG_9, (__VA_ARGS__ , _a8, _a7, _a6, _a5, _a4, _a3, _a2, _a1, _a0))(__VA_ARGS__)
#define SPLAT_SELECT_ARITY_UPTO_9(_a0, _a1, _a2, _a3, _a4, _a5, _a6, _a7, _a8, _a9, ...) SPLAT_SELECTOR_TRAMPOLINE(SPLAT_SELECT_ARG_10, (__VA_ARGS__ , _a9, _a8, _a7, _a6, _a5, _a4, _a3, _a2, _a1, _a0))(__VA_ARGS__)

// a meta seletor can be created which selects the selector based on arg count
