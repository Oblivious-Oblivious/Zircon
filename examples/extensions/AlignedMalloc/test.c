#include "aligned_allocation.h"
#include <stdio.h>

/* #include <unistd.h> */

#define INT_ALIGNMENT 65536

int main(void) {
    int *arr = (int*)aligned_malloc(sizeof(int) * 65536, INT_ALIGNMENT);
    int i;
    int sum = 0;
    
    for(i = 0; i != 65536; i++) {
        arr[i] = 2048;
    }

    /* sleep(20); */

    for(i = 0; i != 65536; i++) {
        sum += arr[i];
    }

    printf("%d\n", sum / 65536);

    aligned_free(arr);
}
