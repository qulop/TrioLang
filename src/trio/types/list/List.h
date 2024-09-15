#ifndef __TRIO_LIST_H
#define __TRIO_LIST_H

#include <stdint.h>
#include <stdbool.h>

#include "ListBase.h"


Trio_List* trio_listCreate();


struct Trio_ListNode* trio_listBegin(Trio_List* list);
struct Trio_ListNode* trio_listRevBegin(Trio_List* list);

struct Trio_ListNode* trio_listEnd(Trio_List* list);
struct Trio_ListNode* trio_listRevEnd(Trio_List* list);

struct Trio_ListNode* trio_listNext(struct Trio_ListNode* node);
struct Trio_ListNode* trio_listRevNext(struct Trio_ListNode* node);

struct Trio_ListNode* trio_listAt(Trio_List* list, uint64_t index);

void trio_listPushBack(Trio_List* list, void* data, size_t sz);
void trio_listPushFront(Trio_List* list, void* data, size_t sz);

bool trio_listInsetData(struct Trio_ListNode* pos, void* data, size_t sz);
bool trio_listInsetNode(struct Trio_ListNode* pos, struct Trio_ListNode* node);

bool trio_listInsertDataAtIndex(Trio_List* list, void* data, size_t sz, uint64_t index);
bool trio_listInsertNodeAtIndex(Trio_List* list, struct Trio_ListNode* node, uint64_t index);


void trio_listFree(Trio_List* list);

#endif