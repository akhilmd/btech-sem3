#include <stdio.h>
#include <stdlib.h>

#define TYPE_FORMAT "%d"

typedef int TYPE;

typedef struct Node
{
    TYPE value;
    struct Node* next;
} Node;

Node* create_from_array(TYPE*, int);
Node* insert_end(Node*, TYPE);
Node* insert_start(Node*, TYPE);
Node* insert_at(Node*, TYPE, int);
Node* delete_element(Node*, TYPE);
Node* delete_end(Node*);
Node* delete_start(Node*);
Node* delete_at(Node*, int);
Node* reverse_list(Node*, Node*);
Node* concatenate_lists(Node*, Node*);
int display_list(char*, Node*);
