#ifndef __TRIO_LIST_BASE_H
#define __TRIO_LIST_BASE_H

#include <stdint.h>


struct _ListNode {
    void* data;

    struct _ListNode* next;
    struct _ListNode* prev;
};

typedef struct {
    struct _ListNode* edge;
    
    uint64_t len;
} Trio_List;



struct _ForwardListNode {
    void* data;

    struct _ForwardListNode* next;
};

typedef struct {
    struct _ForwardListNode* begin;

    uint64_t len;
} Trio_ForwardList;


#endif