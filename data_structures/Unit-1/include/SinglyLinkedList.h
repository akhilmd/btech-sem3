#include <stdio.h>
#include <stdlib.h>

#define SLL_ELEM_TYPE_FORMAT "%d"

typedef int SLL_ELEM_TYPE;

typedef struct Node
{
    SLL_ELEM_TYPE value;
    struct Node* next;
} Node;

Node* sll_create_from_array(SLL_ELEM_TYPE*, int);
Node* sll_insert_end(Node*, SLL_ELEM_TYPE);
Node* sll_insert_start(Node*, SLL_ELEM_TYPE);
Node* sll_insert_at(Node*, SLL_ELEM_TYPE, int);
Node* sll_delete_element(Node*, SLL_ELEM_TYPE);
Node* sll_delete_end(Node*);
Node* sll_delete_start(Node*);
Node* sll_delete_at(Node*, int);
Node* sll_reverse_list(Node*, Node*);
Node* sll_concatenate_lists(Node*, Node*);
int sll_display_list(char*, Node*);