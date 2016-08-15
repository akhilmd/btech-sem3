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
int insert_end(Node**, TYPE);
int insert_start(Node**, TYPE);
int insert_at(Node**, TYPE, int);
int delete_end(Node**);
int delete_start(Node**);
int delete_at(Node**, int);
Node* reverse_list(Node*, Node*);
Node* concatenate_lists(Node*, Node*);
int display_list(char*, Node*);