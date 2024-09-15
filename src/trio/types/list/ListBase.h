#ifndef __TRIO_LIST_BASE_H
#define __TRIO_LIST_BASE_H

#include <stdint.h>


struct Trio_ListNode {
    void* data;

    struct Trio_ListNode* next;
    struct Trio_ListNode* prev;
};

typedef struct {
    struct Trio_ListNode* edge;
    
    uint64_t len;
} Trio_List;



struct Trio_ForwardListNode {
    void* data;

    struct Trio_ForwardListNode* next;
};

typedef struct {
    struct Trio_ForwardListNode* begin;

    uint64_t len;
} Trio_ForwardList;


#endif