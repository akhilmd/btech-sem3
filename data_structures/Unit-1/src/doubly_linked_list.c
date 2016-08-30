#include "../include/DoublyLinkedList.h"

DLLNode* dll_create_from_array(DLL_ELEM_TYPE* ar, int n)
{
    DLLNode* first_node = NULL;

    int i = 0;

    for (i = 0; i < n; ++i)
        first_node = dll_insert_end(first_node, ar[i]);

    return first_node;
}

DLLNode* dll_insert_end(DLLNode* first, DLL_ELEM_TYPE new_val)
{
    DLLNode* new_node = (DLLNode*) malloc(sizeof(DLLNode));
    DLLNode* curr_node = NULL;

    new_node->value = new_val;
    new_node->next = NULL;
    new_node->prev = NULL;

    if (first == NULL)
        first = new_node;
    else
    {
        for (curr_node=first; curr_node->next != NULL; curr_node = curr_node->next)
            ;
        curr_node->next = new_node;
        new_node->prev = curr_node;
    }

    return first;
}

DLLNode* dll_insert_start(DLLNode* first, DLL_ELEM_TYPE new_val)
{
    DLLNode* new_node = (DLLNode*) malloc(sizeof(DLLNode));

    new_node->value = new_val;
    new_node->prev = NULL;
    new_node->next = NULL;

    if (first == NULL)
        return new_node;
    else
    {
        new_node->next = first;
        first->prev = new_node;
        first = new_node;
    }

    return first;
}

DLLNode* dll_insert_at(DLLNode* first, DLL_ELEM_TYPE new_val, int pos)
{
    DLLNode* new_node = (DLLNode*) malloc(sizeof(DLLNode));
    DLLNode* curr_node = NULL;

    // If memory could not be allocated
    if (new_node == NULL)
    {
        printf("ERROR!\n");
        return first;
    }

    new_node->value = new_val;
    new_node->next = NULL;
    new_node->prev = NULL;

    if (pos == 1)
    {
        new_node->next = first;
        new_node->prev = NULL;
        first->prev = new_node;
        first = new_node;
        return first;
    }

    --pos;

    for(curr_node=first;curr_node!=NULL && pos>1; curr_node=curr_node->next, --pos)
        ;

    if (pos != 1)
    {
        printf("Invalid Position!\n");
        return first;
    }

    if (curr_node->next != NULL)
        curr_node->next->prev = new_node;
    new_node->next = curr_node->next;
    new_node->prev = curr_node;
    curr_node->next = new_node;

    return first;
}

DLLNode* dll_delete_element(DLLNode* first, DLL_ELEM_TYPE element)
{
    DLLNode* curr_node = NULL;

    for (curr_node=first; curr_node != NULL && curr_node->value != element;curr_node = curr_node->next)
        ;

    if (curr_node != NULL)
    {
        // If there is only one node
        if ((curr_node->prev == NULL) && (curr_node->next == NULL))
            first = NULL;
        // If first node is to be deleted
        else if (curr_node->prev == NULL)
        {
            first = first->next;
            first->prev = NULL;
        }
        // If last node is to be deleted
        else if (curr_node->next == NULL)
            curr_node->prev->next = NULL;
        else
        {
            curr_node->prev->next = curr_node->next;
            curr_node->next->prev = curr_node->prev;
        }
        free(curr_node);
    }
    else
        printf("Element not found\n");

    return first;
}

DLLNode* dll_delete_end(DLLNode* first)
{
    if (first == NULL)
        printf("Underflow!!");
    else
    {
        DLLNode*  curr_node = NULL;
        for(curr_node = first; curr_node->next != NULL;curr_node = curr_node->next)
            ;
        DLLNode* temp = curr_node;
        if (curr_node->prev != NULL)
            curr_node->prev->next = NULL;
        else
            first = NULL;
        free(temp);
    }

    return first;
}

DLLNode* dll_delete_start(DLLNode* first)
{
    if (first == NULL)
        printf("Underflow!!");
    else
    {
        DLLNode* temp = first;
        first = first->next;
        free(temp);
        first->prev = NULL;
    }

    return first;
}

DLLNode* dll_delete_at(DLLNode* first, int pos)
{
    // Do nothing if list is empty
    if (first == NULL)
        return first;

    DLLNode* curr_node = NULL;

    // Traverse till desired Node by decrementing pos till it reaches 1
    for (curr_node = first; curr_node != NULL && pos > 1;
            curr_node = curr_node->next, --pos)
        ;

    // curr_node can only be NULL if pos is bigger than list length
    if (pos < 1 || curr_node == NULL)
    {
        printf("Invalid Position!\n");
        return first;
    }
    else
    {
        // If pos is 1
        if (curr_node->prev == NULL)
        {
            first = curr_node->next;
            first->prev = NULL;
        }
        else
        {
            curr_node->prev->next = curr_node->next;
            curr_node->next->prev = curr_node->prev;
        }
        free(curr_node);
        return first;
    }

    return first;
}

DLLNode* dll_reverse_list(DLLNode* first)
{
    DLLNode* temp = NULL;
    DLLNode* curr_node = first;

    while (curr_node != NULL)
    {
        temp = curr_node->prev;
        curr_node->prev = curr_node->next;
        curr_node->next = temp;
        curr_node = curr_node->prev;
    }

    if (temp != NULL)
        first = temp->prev;

    return first;
}

void dll_display_list(char* msg, DLLNode* curr_node)
{
    printf("%s", msg);
    if (curr_node == NULL)
        printf("Empty List\n");
    else
    {
        printf("NULL<->");

        for (;curr_node != NULL;curr_node = curr_node->next)
            printf(DLL_ELEM_TYPE_FORMAT "<->", curr_node->value);

        printf("NULL\n");
    }
}
