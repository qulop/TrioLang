#include <types/Vector.h>

#include <stdlib.h>


const float vectorMaximumFullness = 0.8f;    // In percents


void _reallocateVector(Trio_Vector* vec, size_t newCapacity) {
    vec->ptr = realloc(vec->ptr, newCapacity);
    vec->capacity = newCapacity;
}


Trio_Vector* trio_vectorCreate(size_t typeLen, uint32_t initCapacity) {
    uint32_t cap = (initCapacity > 0) ? initCapacity : 16; 

    Trio_Vector* ret = (Trio_Vector*)malloc(sizeof(Trio_Vector));
    ret->ptr = malloc(cap * typeLen);
    ret->capacity = cap;
    ret->dataSize = typeLen;

    return ret;
}


void* trio_vectorBegin(Trio_Vector* vec) {
    return trio_vectorAt(vec, 0);
}


void* trio_vectorEnd(Trio_Vector* vec) {
    return trio_vectorAt(vec, vec->len - 1);
}


void* trio_vectorAt(Trio_Vector* vec, size_t index) {
    return (char*)vec->ptr + (vec->dataSize * index);
}


void trio_vectorPushBack(Trio_Vector* vec, void* data) {
    ++vec->len;

    float currentFullness = (vec->len / vec->capacity);
    if (currentFullness > vectorMaximumFullness) {
        uint32_t newCap = (vec->capacity) + (vec->capacity * 0.5);

        _reallocateVector(&vec, newCap);
    }

    void* targetOffset = (char*)vec->ptr + (vec->dataSize * vec->len);
    targetOffset = data;
}


void trio_vectorFree(Trio_Vector* vec) {
    free(vec->ptr);
    free(vec);
}