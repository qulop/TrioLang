#include "ForwardList.h"

#include <assert.h>


#define NODE    struct _ForwardListNode


Trio_ForwardList* trio_forwardListCreate() {
    Trio_ForwardList* ret = (Trio_ForwardList*)malloc(sizeof(Trio_ForwardList));
    ret->begin = NULL;
    ret->len = 0;

    return ret;
}


struct _ForwardListNode* trio_forwardListBegin(Trio_ForwardList* list) {
    return (list) ? list->begin : NULL;
}

struct _ForwardListNode* trio_forwardListNext(struct _ForwardListNode* node) {
    return (node != NULL && node->data != NULL) ? node->next : NULL;
}





void trio_forwardListFree(Trio_ForwardList* list) {
    NODE* begin = trio_forwardListBegin(list);

    do {
        free(begin->data);
        free(begin);
    } while ((begin = trio_forwardListNext(begin)) != NULL);
}