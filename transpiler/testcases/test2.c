#include "assert.h"
#include <stdio.h>
#include "stdlib.h"

static unsigned long long calculate(unsigned long long index) {
    return 3 * index * (index + 1) / 2;
}

static unsigned long long finance(unsigned long long n) {
    unsigned long long index = 0;
    unsigned long long result = 0;

    for(index = 0; index <= n; ++index) {
        result += calculate(index);
    }

    return result;
}

int main(int argc, char **argv) {
    assert(argc == 1);

    printf("%d\n", finance(24));
    return 0;
}
