#ifndef __TRIO_VECTOR_H
#define __TRIO_VECTOR_H

#include <stdint.h>


typedef struct {
    void* ptr;
    size_t len;

    uint32_t capacity;
    size_t dataSize;
} Trio_Vector;


Trio_Vector* trio_vectorCreate(size_t typeLen, size_t initCapacity);

void* trio_vectorBegin(Trio_Vector* vec);
void* trio_vectorEnd(Trio_Vector* vec);

void* trio_vectorAt(Trio_Vector* vec, size_t index);

void trio_vectorPushBack(Trio_Vector* vec, void* data);
// void trio_vectorInsertAt(Trio_Vector* vec, void* data, size_t i);

void trio_vectorFree(Trio_Vector* vec);

#endif