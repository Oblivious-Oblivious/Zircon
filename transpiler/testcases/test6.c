#ifndef __TEST6_H_
#define __TEST6_H_

#define A 21
#define B 2

#include <stdio.h>
#include <assert.h>

#endif

int main(int argc, char **argv) {
    assert(argc == 1);

    int r = A * B;
    printf("%d\n", r);

    return r - 42;
}
