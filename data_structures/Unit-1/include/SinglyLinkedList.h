#include <stdio.h>
#include <stdlib.h>

#define SLL_ELEM_TYPE_FORMAT "%d"

typedef int SLL_ELEM_TYPE;

typedef struct SLLNode
{
    SLL_ELEM_TYPE value;
    struct SLLNode* next;
} SLLNode;

SLLNode* sll_create_from_array(SLL_ELEM_TYPE*, int);
SLLNode* sll_insert_end(SLLNode*, SLL_ELEM_TYPE);
SLLNode* sll_insert_start(SLLNode*, SLL_ELEM_TYPE);
SLLNode* sll_insert_at(SLLNode*, SLL_ELEM_TYPE, int);
SLLNode* sll_delete_element(SLLNode*, SLL_ELEM_TYPE);
SLLNode* sll_delete_end(SLLNode*);
SLLNode* sll_delete_start(SLLNode*);
SLLNode* sll_delete_at(SLLNode*, int);
SLLNode* sll_reverse_list(SLLNode*, SLLNode*);
SLLNode* sll_concatenate_lists(SLLNode*, SLLNode*);
int sll_display_list(char*, SLLNode*);