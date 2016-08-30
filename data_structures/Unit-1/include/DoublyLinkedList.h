#include <stdio.h>
#include <stdlib.h>

#define DLL_ELEM_TYPE_FORMAT "%d"

typedef int DLL_ELEM_TYPE;

typedef struct DLLNode
{
    DLL_ELEM_TYPE value;
    struct DLLNode* next;
    struct DLLNode* prev;
} DLLNode;

DLLNode* dll_create_from_array(DLL_ELEM_TYPE*, int);
DLLNode* dll_insert_end(DLLNode*, DLL_ELEM_TYPE);
DLLNode* dll_insert_start(DLLNode*, DLL_ELEM_TYPE);
DLLNode* dll_insert_at(DLLNode*, DLL_ELEM_TYPE, int);
DLLNode* dll_delete_element(DLLNode*, DLL_ELEM_TYPE);
DLLNode* dll_delete_end(DLLNode*);
DLLNode* dll_delete_start(DLLNode*);
DLLNode* dll_delete_at(DLLNode*, int);
DLLNode* dll_reverse_list(DLLNode*);
void dll_display_list(char*, DLLNode*);
