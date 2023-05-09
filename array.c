//
// Created by mustafif on 5/9/23.
//

#include <stdlib.h>
#include <stdio.h>
#include "array.h"

void* reallocate(void* pointer, size_t oldSize, size_t newSize){
    // if newSize is 0, we free pointer
    if (newSize == 0){
        free(pointer);
        return NULL;
    }
    // we use realloc to handle any grow, shrink, etc.
    void* result = realloc(pointer, newSize);
    // if allocation failed, exit the program
    if (result == NULL) exit(1);
    return result;
}

// create a new empty vector
void initVector(Vector* vector){
    vector->values = NULL;
    vector->capacity = 0;
    vector->count = 0;
}

// difference between using `->` and `.`
// for `->` is used for Foo* where Foo is a struct
// for `.` is used for Foo where """"

/*
 * // count is 3
 * [1, 2, 3]
 * // push 4, index is going to be 3 == count
 */



// push to the array
void pushVector(Vector* vector, int value){
    // we check if it's full
    if(vector->count == vector->capacity){
        int oldCapacity = vector->capacity;
        vector->capacity = GROW_CAPACITY(oldCapacity);
        vector->values = GROW_ARRAY(int, vector->values, oldCapacity, vector->capacity);
    }
    // append to the array
    vector->values[vector->count] = value;
    // increase count of array
    vector->count++;
}

int popVector(Vector* vector){
    // decrement count
    vector->count--;
    return vector->values[vector->count];
}

void freeVector(Vector* vector){
    printf("Freeing vector\n");
    // free pointer
    FREE_ARRAY(int, vector->values, vector->capacity);
    // resets to empty vector
    initVector(vector);
}


