#include <types/BidirectionalList.h>
#include <utility/TrioUtils.h>

#include <stdlib.h>


#define NODE    struct _ListNode


NODE* _allocateNewNode() {
    NODE* ret = (NODE*)malloc(sizeof(NODE));
    return ret;
}

NODE* _allocateNewNodeAndCopyData(void* data, size_t sz) {
    NODE* newNode = _allocateNewNode();
    newNode->data = trio_copy(data, sz);

    return newNode;
}

void _setNode(NODE* target, NODE* next, NODE* prev) {
    target->next = next;
    target->prev = prev;
}

void _initEdge(NODE* edge) {
    edge->data = NULL;
    _setNode(edge, edge, edge);
}


Trio_List* trio_listCreate() {
    Trio_List* ret = (Trio_List*)malloc(sizeof(Trio_List));
    ret->edge = _allocateNewNode();
    ret->len = 0;

    _initEdge(ret->edge);

    return ret;
}


struct _ListNode* trio_listBegin(Trio_List* list) {
    return (list) ? list->edge->next : NULL; 
}

struct _ListNode* trio_listRevBegin(Trio_List* list) {
    return trio_listEnd(list);
}


struct _ListNode* trio_listEnd(Trio_List* list) {
    return (list) ? list->edge->prev : NULL; 
}

struct _ListNode* trio_listRevEnd(Trio_List* list) {
    return trio_listBegin(list);
}


struct _ListNode* trio_listNext(struct _ListNode* node) {
    return (node) ? node->next : NULL;
}   

struct _ListNode* trio_listRevNext(struct _ListNode* node) {
    return (node) ? node->prev : NULL;
}

struct _ListNode* trio_listAt(Trio_List* list, uint64_t index) {
    if (index == -1)
        return (list->len) ? list->edge->prev : NULL;

    NODE* n = trio_listBegin(list);
    for (int i = 0; n != trio_listEnd(list);  i++) {
        if (i == index)
            return n;

        n = trio_listNext(n);
    }

    return NULL;
}

void trio_listPushBack(Trio_List* list, void* data, size_t sz) {
    NODE* newNode = _allocateNewNodeAndCopyData(data, sz);

    // if list created manually(using malloc instead of trio_listCreate())
    if (!list->edge) {
        list->edge = _allocateNewNode();
        _initEdge(list);
        list->size = 0;
    }

    NODE* edge = list->edge;
    NODE* prev = edge->prev;

    prev->next = newNode;
    edge->prev = newNode;
    _setNode(newNode, edge, prev);

    list->size += 1;
}

void trio_listPushFront(Trio_List* list, void* data, size_t sz) {

}


bool trio_listInsetData(struct _ListNode* pos, void* data, size_t sz) {
    if (!pos)
        return false;

    NODE* newNode = _allocateNewNodeAndCopyData(data, sz);



    return true;
}

bool trio_listInsetNode(struct _ListNode* pos, struct _ListNode* node) {
    if (!pos)
        return false;

    NODE* newNode = _allocateNewNodeAndCopyData(node, sizeof(NODE));

    pos->prev->next = newNode;
    newNode->prev = pos->prev;

    pos->prev = newNode;
    newNode->next = pos;
    
    return true;
}



void trio_listFree(Trio_List* list) {
    NODE* n = list->edge->next; // First node

    while (n != list->edge) {
        NODE* next = n->next;

        free(n->data);
        free(n);

        n = next;
    }

    free(list->edge);
    free(list);
}