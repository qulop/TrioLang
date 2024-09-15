#ifndef __TRIO_HASH_TABLE_H
#define __TRIO_HASH_TABLE_H

#include <types/Vector.h>

#include <stdbool.h>
#include <stdlib.h>


typedef struct{
    Trio_Vector* buckets;
    uint64_t len;

    uint64_t capacity;
} Trio_HashTable;


uint64_t trio_hashString(const char* val, int maxLen);
uint64_t trio_hashInteger(int val, int maxLen);
uint64_t trio_hashFloat(float val, int maxLen);
uint64_t trio_hashDouble(float val, int maxLen);
uint64_t trio_hashChar(char ch, int maxLen);


Trio_HashTable* trio_hashTableCreate(uint64_t initCap);

void trio_hashTableInsert(Trio_HashTable* table, uint64_t hashedKey, void* val);
void trio_hashTableInsertString(Trio_HashTable* table, const char* key, void* val);
void trio_hashTableInsertInteger(Trio_HashTable* table, int key, void* val);
void trio_hashTableFloat(Trio_HashTable* table, float key, void* val);
void trio_hashTableInsertDouble(Trio_HashTable* table, double key, void* val);
void trio_hashTableInsertChar(Trio_HashTable* table, char key, void* val);


bool trio_hashTableIsKeyExists(Trio_HashTable* table, uint64_t hashedKey);
bool trio_hashTableFindValue(Trio_HashTable* table, void* val);

void trio_hashTableFree(Trio_HashTable* table);

#endif