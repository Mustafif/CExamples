//
// Created by mustafif on 5/9/23.
//

#ifndef EXAMPLES_ARRAY_H
#define EXAMPLES_ARRAY_H

#include <stddef.h>

typedef struct {
    int capacity;
    int count;
    int* values;
}Vector;

// methods
// create a new vector
// push a new value (to the back)
// pop a value (remove from back)
// free it

void initVector(Vector* vector);
void pushVector(Vector* vector, int value);
int popVector(Vector* vector);
void freeVector(Vector* vector);
void* reallocate(void* pointer, size_t oldSize, size_t newSize);
/*
 * cap: 3, len: 3
 * [1, 2, 3]
 * push 4 ?
 * cap == len
 * because it's full, we grow cap * 2
 * cap: 6, len: 4
 * [1, 2, 3, 4, .. , ..]
 */
//> Grows capacity
#define GROW_CAPACITY(capacity) \
    ((capacity) < 8 ? 8: (capacity) * 2)
//> Grows array
#define GROW_ARRAY(type, pointer, oldCount, newCount) \
    (type*)reallocate(pointer, sizeof(type)*(oldCount), \
    sizeof(type) * (newCount))
#define FREE_ARRAY(type, pointer, oldCount) \
        reallocate(pointer, sizeof(type) * (oldCount), 0)
#endif //EXAMPLES_ARRAY_H
