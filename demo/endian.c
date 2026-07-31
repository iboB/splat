#include <splat/endian.h>
#include <stdio.h>

int main() {
    const char* estr = HOST_IS_BIG_ENDIAN ? "big" : "little";
    printf("Host is %s-endian\n", estr);
    return 0;
}
