// Copyright (c) Borislav Stanimirov
// SPDX-License-Identifier: MIT
//
#include <splat/pp_select.h>
#include <stdio.h>

int sum1(int a) {
    return a;
}

int sum2(int a, int b) {
    return a + b;
}

int sum3(int a, int b, int c) {
    return a + b + c;
}

#define ADD_1(a, _) (a + 1)

int main() {
    int s3 = sum3(SPLAT_ITERATE_WITH(ADD_1, 1, 2, 3));
    printf("s3: %d\n", s3);

    int vs = SPLAT_SELECT_ARITY_UPTO_3(_, sum1, sum2, sum3, 10, 20);
    printf("vs: %d\n", vs);

    return 0;
}
