#include <stdio.h>
#include <stdlib.h>

#define dll_ELEM_TYPE_FORMAT "%d"

typedef int DLL_ELEM_TYPE;

typedef struct Node {
	DLL_ELEM_TYPE data;
	struct Node* next;
	struct Node* prev;
} Node;

Node* dll_create_from_array(DLL_ELEM_TYPE*, int);
Node* dll_insert_end(Node*, DLL_ELEM_TYPE);
Node* dll_insert_start(Node*, DLL_ELEM_TYPE);
Node* dll_delete_element(Node*, DLL_ELEM_TYPE);
Node* dll_delete_end(Node*);
Node* dll_delete_start(Node*);
Node* dll_delete_at(Node*, int);
Node* dll_reverse_list(Node*);
void dll_display_list(char*, Node*);
