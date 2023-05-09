#include <stdio.h>
#include "array.h"

int main() {
    // create an uninit vector
    Vector vector;
    // initialize vector
    initVector(&vector);

    // push values
    pushVector(&vector, 32);
    pushVector(&vector, 45);

    printf("Count is %d\n", vector.count);
    printf("Capacity is %d\n", vector.capacity);

    int result = popVector(&vector);
    printf("Popped value is %d\n", result);

    printf("Count is %d\n", vector.count);

    freeVector(&vector);
    return 0;
}
