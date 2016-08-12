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
char insert_end(Node**, TYPE);
char insert_start(Node**, TYPE);
char insert_at(Node**, TYPE, int);
char delete_end(Node**);
char delete_start(Node**);
char delete_at(Node**, int);
Node* reverse_list(Node*, Node*);
Node* concatenate_lists(Node*, Node*);
char display_list(char*, Node*);