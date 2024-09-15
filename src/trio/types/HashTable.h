#ifndef __TRIO_HASH_TABLE_H
#define __TRIO_HASH_TABLE_H

#include <types/Vector.h>

#include <stdbool.h>


typedef struct{
    Trio_Vector* buckets;
    uint64_t len;

    uint64_t capacity;
} Trio_HashTable;


uint64_t trio_hashString(const char* val, int tableLen);
uint64_t trio_hashInteger(int val, int tableLen);
uint64_t trio_hashFloat(float val, int tableLen);
uint64_t trio_hashDouble(float val, int tableLen);
uint64_t trio_hashChar(char ch, int tableLen);


Trio_HashTable* trio_hashTableCreate(size_t initSz);

void trio_hashTableInsert(uint64_t hashedKey, void* val);

bool trio_hashTableFindKey(uint64_t hashedKey);
bool trio_hashTableFindValue(void* val);



#endif