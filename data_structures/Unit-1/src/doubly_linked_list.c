#include "../include/DoublyLinkedList.h"

DLLNode* dll_create_from_array(DLL_ELEM_TYPE* ar, int n)
{
    DLLNode* first_node = NULL;

    int i = 0;

    for (i = 0; i < n; ++i)
        first_node = dll_insert_end(first_node, ar[i]);

    return first_node;
}

DLLNode *dll_insert_start(DLLNode *head_ref, DLL_ELEM_TYPE element)
{

    DLLNode *temp;
    temp = (DLLNode*) malloc(sizeof(DLLNode));
    temp->data = element;
    temp->prev = NULL;
    temp->next = NULL;
    if (head_ref == NULL)
        return temp;
    else
    {

        temp->next = head_ref;
        head_ref->prev = temp;
        head_ref = temp;
        return head_ref;
    }
}

void dll_display_list(char* msg, DLLNode *q)
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

DLLNode *dll_insert_end(DLLNode *head_ref, DLL_ELEM_TYPE element)
{

    DLLNode *temp, *q;
    temp = (DLLNode*) malloc(sizeof(DLLNode));
    temp->data = element;
    temp->next = NULL;
    temp->prev = NULL;

    if (head_ref == NULL)
        head_ref = temp;
    else
    {
        q = head_ref;
        while (q->next != NULL)
            q = q->next;
        q->next = temp;
        temp->prev = q;
    }

    return head_ref;
}

DLLNode *dll_delete_element(DLLNode *head_ref, DLL_ELEM_TYPE element)
{
    DLLNode *q;
    q = head_ref;

    while ((q != NULL) && (q->data != element))
        q = q->next;

    if (q != NULL)
    {
        // if only one node in the list
        if ((q->prev == NULL) && (q->next == NULL))
            head_ref = NULL; //make first NULL
        else if (q->prev == NULL) //first node
        {
            head_ref = q->next;
            (head_ref)->prev = NULL;
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

    return head_ref;

}

DLLNode *dll_delete_start(DLLNode *head_ref)
{
    if (head_ref == NULL)
        printf("Underflow!!");
    else
    {
        DLLNode *temp = head_ref;
        head_ref = head_ref->next;
        free(temp);
        head_ref->prev = NULL;
    }

    return head_ref;
}

DLLNode *dll_delete_end(DLLNode *head_ref)
{
    if (head_ref == NULL)
        printf("Underflow!!");
    else
    {
        DLLNode *q = head_ref;
        while (q->next->next != NULL)
            q = q->next;

        DLLNode *temp = q->next;
        q->next = NULL;
        free(temp);
    }

    return head_ref;
}

DLLNode *dll_insert_at(DLLNode *head_ref, DLL_ELEM_TYPE element, int pos)
{
    int i = 0;
    DLLNode *q, *temp;
    q = head_ref;

    temp = (DLLNode*) malloc(sizeof(DLLNode));
    temp->data = element;
    temp->next = NULL;
    temp->prev = NULL;

    if (pos == 1)
        dll_insert_start(head_ref, element);

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

    return head_ref;

}

DLLNode* dll_reverse_list(DLLNode *head_ref)
{
    DLLNode *temp = NULL;
    DLLNode *current = head_ref;

    while (current != NULL)
    {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }

    if (temp != NULL)
        head_ref = temp->prev;

    return head_ref;
}
