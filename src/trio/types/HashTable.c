#include "HashTable.h"
#include <types/list/ForwardList.h>

#include <assert.h>


// --- BASE ----
typedef struct {
    int64_t hashedKey;
    void* data;

} _BucketItem;

static const uint32_t FILL_FACTOR = 70u;
// ----------


uint32_t _getLoadFactor(Trio_HashTable* table) {
    return (table->len / table->capacity) * 100;
}


_BucketItem* _allocateBucketItem(int64_t hashedKey, void* data) {
    _BucketItem* ret = (_BucketItem*)malloc(sizeof(_BucketItem));
    ret->hashedKey = hashedKey;
    ret->data = data;

    return ret;
}


struct Trio_ForwardListNode* _getBeginOfBucket(Trio_HashTable* table, uint64_t hashedKey) {
    Trio_ForwardList* requiredList = (Trio_ForwardList*)trio_vectorAt(table->buckets, hashedKey);
    return trio_forwardListBegin(requiredList);
}


void _freeTable(Trio_HashTable* table) {
    if (!table)
        return;

    Trio_Vector* buckets = table->buckets;
    for (int i = 0; i < buckets->capacity; i++) {
        Trio_ForwardList* bucket = trio_vectorAt(buckets, i);

        struct Trio_ForwardListNode* begin = bucket->begin;
        for (begin; begin != NULL; begin = trio_forwardListNext(begin)) {
            _BucketItem* item = (_BucketItem*)begin->data;
            free(item);
        }

        free(bucket);
    }

    free(buckets);
    free(table);
}


void _reallocateTable(Trio_HashTable* table, uint64_t newCap) {

}



uint64_t trio_hashString(const char* val, int maxLen) {

}

uint64_t trio_hashInteger(int val, int maxLen) {

}

uint64_t trio_hashFloat(float val, int maxLen) {

}

uint64_t trio_hashDouble(float val, int maxLen) {

}

uint64_t trio_hashChar(char ch, int maxLen) {

}



Trio_HashTable* trio_hashTableCreate(uint64_t initCap) {
    Trio_HashTable* ret = (Trio_HashTable*)malloc(sizeof(Trio_HashTable));
    ret->len = 0;
    ret->buckets = trio_vectorCreate(sizeof(Trio_ForwardList), initCap);
    ret->capacity = ret->buckets->capacity;

    Trio_Vector* buckets = ret->buckets;
    for (int i = 0; i < ret->capacity; i++) {
        buckets->ptr = trio_forwardListCreate();

        Trio_ForwardList* ptr = (Trio_ForwardList*)buckets->ptr;
        _BucketItem* item = _allocateBucketItem(-1, NULL);
        trio_forwardListPushFront(ptr, item, sizeof(_BucketItem));
    }

    return ret;
}


void trio_hashTableInsert(Trio_HashTable* table, uint64_t hashedKey, void* val) {
    assert(hashedKey < table->capacity);

    if (_getLoadFactor(table) > FILL_FACTOR)
        _reallocateTable(table, (table->capacity * 2u) + 1u);

    struct Trio_ForwardListNode* begin = _getBeginOfBucket(table, hashedKey);

    _BucketItem* targetItem = NULL;
    for (begin; begin != NULL ; begin = trio_forwardListNext(begin)) {
        targetItem = (_BucketItem*)begin->data;

        if (targetItem->hashedKey == -1)
            return;
    }

    targetItem->hashedKey = hashedKey;
    targetItem->data = val;
}


void trio_hashTableInsertString(Trio_HashTable* table, const char* key, void* val) {
    trio_hashTableInsert(table, trio_hashString(key, table->capacity) , val);
}

void trio_hashTableInsertInteger(Trio_HashTable* table, int key, void* val) {
    trio_hashTableInsert(table, trio_hashInteger(key, table->capacity) , val);
}

void trio_hashTableFloat(Trio_HashTable* table, float key, void* val) {
    trio_hashTableInsert(table, trio_hashFloat(key, table->capacity) , val);
}

void trio_hashTableInsertDouble(Trio_HashTable* table, double key, void* val) {
    trio_hashTableInsert(table, trio_hashDouble(key, table->capacity) , val);
}

void trio_hashTableInsertChar(Trio_HashTable* table, char key, void* val) {
    trio_hashTableInsert(table, trio_hashChar(key, table->capacity) , val);
}


bool trio_hashTableIsKeyExists(Trio_HashTable* table, uint64_t hashedKey) {
    assert(hashedKey < table->capacity);

    _BucketItem* firstItem = (_BucketItem*)_getBeginOfBucket(table, hashedKey)->data;
    return (firstItem->hashedKey == hashedKey) ? true : false;
}


bool trio_hashTableFindValue(Trio_HashTable* table, void* val) {
    
}


void trio_hashTableFree(Trio_HashTable* table) {
    _freeTable(table);
}


