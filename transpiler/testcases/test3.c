#include <stdio.h>
#include <stdlib.h>

typedef struct sth {
    int a;
} sth;

typedef void* (*lambda)();

int main(void) {
    sth *test = (sth*)malloc(sizeof(sth));
    test->a = 42;
    printf("%d\n", test->a);
}
