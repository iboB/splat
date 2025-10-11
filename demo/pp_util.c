// Copyright (c) Borislav Stanimirov
// SPDX-License-Identifier: MIT
//
#include <splat/pp_util.h>
#include <stdio.h>

int main() {
    // test CAT
    int SPLAT_PP_CAT(hello, world) = 42;
    printf("CAT: %d\n", helloworld);
    // test STRINGIZE
    printf("STRINGIZE: %s\n", SPLAT_PP_STRINGIZE(hello world));
    return 0;
}
