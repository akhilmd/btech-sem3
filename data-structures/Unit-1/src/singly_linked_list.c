#include "../include/SinglyLinkedList.h"

SLLNode* sll_create_from_array(SLL_ELEM_TYPE* ar, int n)
{
    SLLNode* first_node = NULL;

    int i = 0;

    for (i = 0; i < n; ++i)
        first_node = sll_insert_end(first_node, ar[i]);

    return first_node;
}

SLLNode* sll_insert_end(SLLNode* first, SLL_ELEM_TYPE in_val)
{
    SLLNode* new_node = (SLLNode*) malloc(sizeof(SLLNode));

    // If memory could not be allocated
    if (new_node == NULL)
    {
        printf("ERROR!\n");
        return first;
    }

    new_node->value = in_val;
    new_node->next = NULL;

    // If list is empty
    if (first == NULL)
    {
        first = new_node;
        return first;
    }

    else
    {
        SLLNode* curr_node = first;

        // Traverse till the last Node
        for (; curr_node->next != NULL; curr_node = curr_node->next)
            ;

        curr_node->next = new_node;
    }

    return first;
}

SLLNode* sll_insert_start(SLLNode* first, SLL_ELEM_TYPE in_val)
{
    SLLNode* new_node = (SLLNode*) malloc(sizeof(SLLNode));

    // If memory could not be allocated
    if (new_node == NULL)
    {
        printf("ERROR!\n");
        return first;
    }

    // new Node points to first Node
    new_node->value = in_val;
    new_node->next = first;
    // new Node becomes new first Node
    first = new_node;

    return first;
}

SLLNode* sll_insert_at(SLLNode* first, SLL_ELEM_TYPE in_val, int pos)
{
    SLLNode* new_node = (SLLNode*) malloc(sizeof(SLLNode));
    SLLNode* prev_node = NULL;
    SLLNode* curr_node = NULL;

    // If memory could not be allocated
    if (new_node == NULL)
    {
        printf("ERROR!\n");
        return first;
    }

    new_node->value = in_val;
    new_node->next = NULL;

    // Traverse till Node at position to insert in
    for (curr_node = first; curr_node != NULL && pos > 1; prev_node =
            curr_node, curr_node = curr_node->next, --pos)
        ;

    // pos is greater than number of nodes or less than 1
    if (pos!=1)
    {
        printf("Invalid Position!\n");
        return first;
    }
    else
    {
        new_node->next = curr_node;

        // If pos is 1
        if (prev_node == NULL)
            first = new_node;
        else
            prev_node->next = new_node;

        return first;
    }
}

SLLNode* sll_delete_element(SLLNode* first, SLL_ELEM_TYPE element)
{
    SLLNode *head, *prev;
    head = first;
    prev = NULL;

    while ((head != NULL) && (head->value != element))
    {
        prev = head;
        head = head->next;
    }

    if (head == NULL)
        printf("Node Not Found\n");
    else
    {

        if (prev == NULL)
            first = head->next;
        else
            prev->next = head->next;
        free(head);
    }

    return first;
}

SLLNode* sll_delete_start(SLLNode* first)
{
    SLLNode *to_be_freed = first;

    // Second Node is the new first Node
    first = first->next;
    // Free memory occupied by original first Node
    free(to_be_freed);

    return first;
}

SLLNode* sll_delete_end(SLLNode* first)
{
    // Do nothing if list is empty
    if (first == NULL)
        return first;

    SLLNode* prev_node = NULL;
    SLLNode* curr_node = NULL;

    // Traverse till last Node.
    for (curr_node = first; curr_node->next != NULL; prev_node =
            curr_node, curr_node = curr_node->next)
        ;

    // Previous node is new last Node
    prev_node->next = NULL;
    // Free Last node
    free(curr_node);

    return first;
}

SLLNode* sll_delete_at(SLLNode* first, int pos)
{
    // Do nothing if list is empty
    if (first == NULL)
        return first;

    SLLNode* prev_node = NULL;
    SLLNode* curr_node = NULL;

    // Traverse till desired Node by decrementing pos till it reaches 1
    for (curr_node = first; curr_node != NULL && pos > 1; prev_node =
            curr_node, curr_node = curr_node->next, --pos)
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
        if (prev_node == NULL)
            first = curr_node->next;
        else
            prev_node->next = curr_node->next;
        free(curr_node);
        return first;
    }

    return first;
}

SLLNode* sll_reverse_list(SLLNode* prev, SLLNode* curr)
{
    SLLNode* next = NULL;

    if (curr == NULL)
        return NULL;
    else
    {
        next = curr->next;
        curr->next = prev;
    }

    // Base condition.
    if (next == NULL)
        return curr;

    return sll_reverse_list(curr, next);
}

SLLNode* sll_concatenate_lists(SLLNode* list1, SLLNode* list2)
{
    SLLNode* curr_node = NULL;

    for (curr_node = list1; curr_node != NULL; curr_node = curr_node->next)
        if (curr_node->next == NULL)
        {
            curr_node->next = list2;
            return list1;
        }

    return NULL;
}

int sll_display_list(char* msg, SLLNode* curr_node)
{
    printf("%s", msg);
    for (; curr_node != NULL; curr_node = curr_node->next)
        printf(SLL_ELEM_TYPE_FORMAT "->", curr_node->value);
    printf("NULL\n");

    return 0;
}
