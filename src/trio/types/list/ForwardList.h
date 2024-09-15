#ifndef __TRIO_FORWARD_LIST_H
#define __TRIO_FORWARD_LIST_H

#include <stdint.h>

#include "ListBase.h"



Trio_ForwardList* trio_forwardListCreate();


struct Trio_ForwardListNode* trio_forwardListBegin(Trio_ForwardList* list);

struct Trio_ForwardListNode* trio_forwardListNext(struct Trio_ForwardListNode* node);

struct Trio_ForwardListNode* trio_forwardListAt(Trio_ForwardList* list, uint64_t index);

void trio_forwardListPushBack(Trio_ForwardList* list, void* data, size_t sz);
void trio_forwardListPushFront(Trio_ForwardList* list, void* data, size_t sz);


void trio_forwardListFree(Trio_ForwardList* list);

#endif