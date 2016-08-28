#include "../include/DoublyLinkedList.h"

DLLNode* dll_create_from_array(DLL_ELEM_TYPE* ar, int n)
{
    DLLNode* first_node = NULL;

    int i = 0;

    for (i = 0; i < n; ++i)
        first_node = dll_insert_end(first_node, ar[i]);

    return first_node;
}

DLLNode* dll_insert_end(DLLNode* first, DLL_ELEM_TYPE element)
{
    DLLNode* temp = (DLLNode*) malloc(sizeof(DLLNode));
    DLLNode* q = NULL;
    temp->data = element;
    temp->next = NULL;
    temp->prev = NULL;

    if (first == NULL)
        first = temp;
    else
    {
        q = first;
        while (q->next != NULL)
            q = q->next;
        q->next = temp;
        temp->prev = q;
    }

    return first;
}

DLLNode* dll_insert_start(DLLNode* first, DLL_ELEM_TYPE element)
{
    DLLNode* temp = (DLLNode*) malloc(sizeof(DLLNode));
    temp->data = element;
    temp->prev = NULL;
    temp->next = NULL;
    if (first == NULL)
        return temp;
    else
    {
        temp->next = first;
        first->prev = temp;
        first = temp;
        return first;
    }
}

DLLNode* dll_insert_at(DLLNode* first, DLL_ELEM_TYPE element, int pos)
{
    int i = 0;
    DLLNode* q = first;
    DLLNode* temp = (DLLNode*) malloc(sizeof(DLLNode));
    temp->data = element;
    temp->next = NULL;
    temp->prev = NULL;

    if (pos == 1)
        dll_insert_start(first, element);
    else
    {
        for (i = 1; (q->next != NULL) && (i < pos); ++i)
            q = q->next;

        if (i == pos) //insert in middle before q;
        {
            q->prev->next = temp;
            temp->prev = q->prev;
            temp->next = q;
            q->prev = temp;
        }
        else if (i == pos - 1) //insert end
        {
            q->next = temp;
            temp->prev = q;
        }
        else
            printf("Invalid position");
    }

    return first;
}

DLLNode* dll_delete_element(DLLNode* first, DLL_ELEM_TYPE element)
{
    DLLNode* q = first;

    while ((q != NULL) && (q->data != element))
        q = q->next;

    if (q != NULL)
    {
        // if only one node in the list
        if ((q->prev == NULL) && (q->next == NULL))
            first = NULL; //make first NULL
        else if (q->prev == NULL) //first node
        {
            first = q->next;
            (first)->prev = NULL;
        }
        else if (q->next == NULL) //last node
            q->prev->next = NULL;
        else //middle
        {
            q->prev->next = q->next;
            q->next->prev = q->prev;
        }
        free(q);
    }
    else
        printf("NODE not found\n");

    return first;
}

DLLNode* dll_delete_end(DLLNode* first)
{
    if (first == NULL)
        printf("Underflow!!");
    else
    {
        DLLNode* q = first;
        while (q->next->next != NULL)
            q = q->next;

        DLLNode* temp = q->next;
        q->next = NULL;
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
    DLLNode* current = first;

    while (current != NULL)
    {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }

    if (temp != NULL)
        first = temp->prev;

    return first;
}

void dll_display_list(char* msg, DLLNode* q)
{
    printf("%s", msg);
    if (q == NULL)
        printf("Empty List\n");
    else
    {
        printf("NULL<->");

        while (q != NULL)
        {
            printf(DLL_ELEM_TYPE_FORMAT "<->", q->data);
            q = q->next;
        }

        printf("NULL\n");
    }
}
