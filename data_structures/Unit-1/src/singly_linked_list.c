#include "../include/SinglyLinkedList.h"

Node* create_from_array(TYPE* ar, int n)
{
    Node* first_node = NULL;

    int i = 0;

    for (i = 0; i < n; ++i)
        insert_end(&first_node, ar[i]);

    return first_node;
}

int insert_end(Node** ptr_first, TYPE in_val)
{
    Node* new_node = (Node*) malloc(sizeof(Node));

    // If memory could not be allocated
    if (new_node == NULL)
    {
        printf("ERROR!\n");
        return 1;
    }

    new_node->value = in_val;
    new_node->next = NULL;

    // If list is empty
    if ((*ptr_first) == NULL)
    {
        (*ptr_first) = new_node;
        return 0;
    }
    else
    {
        Node* curr_node = (*ptr_first);

        // Traverse till the last Node
        for (; curr_node->next != NULL; curr_node = curr_node->next)
            ;

        curr_node->next = new_node;
        return 0;
    }
}

int insert_start(Node** ptr_first, TYPE in_val)
{
    Node* new_node = (Node*) malloc(sizeof(Node));

    // If memory could not be allocated
    if (new_node == NULL)
    {
        printf("ERROR!\n");
        return 1;
    }

    // new Node points to first Node
    new_node->value = in_val;
    new_node->next = (*ptr_first);
    // new Node becomes new first Node
    (*ptr_first) = new_node;

    return 0;
}

int insert_at(Node** ptr_first, TYPE in_val, int pos)
{
    Node* new_node = (Node*) malloc(sizeof(Node));
    Node* prev_node = NULL;
    Node* curr_node = NULL;

    // If memory could not be allocated
    if (new_node == NULL)
    {
        printf("ERROR!\n");
        return 1;
    }

    new_node->value = in_val;
    new_node->next = NULL;

    // Traverse till Node at position to insert in
    for (curr_node = (*ptr_first); curr_node != NULL && pos > 1; prev_node =
            curr_node, curr_node = curr_node->next, --pos)
        ;

    // pos is greater than number of nodes or less than 1
    if (curr_node == NULL || pos < 1)
    {
        printf("Invalid Position!\n");
        return 1;
    }
    else
    {
        new_node->next = curr_node;

        // If pos is 1
        if (prev_node == NULL)
            (*ptr_first) = new_node;
        else
            prev_node->next = new_node;

        return 0;
    }
}

int delete_start(Node** ptr_first)
{
    Node *to_be_freed = *ptr_first;

    // Second Node is the new first Node
    (*ptr_first) = (*ptr_first)->next;
    // Free memory occupied by original first Node
    free(to_be_freed);

    return 0;
}

int delete_end(Node** ptr_first)
{
    // Do nothing if list is empty
    if ((*ptr_first) == NULL)
        return 0;

    Node* prev_node = NULL;
    Node* curr_node = NULL;

    // Traverse till last Node.
    for (curr_node = (*ptr_first); curr_node->next != NULL; prev_node =
            curr_node, curr_node = curr_node->next)
        ;

    // Previous node is new last Node
    prev_node->next = NULL;
    // Free Last node
    free(curr_node);

    return 0;
}

int delete_at(Node** ptr_first, int pos)
{
    // Do nothing if list is empty
    if ((*ptr_first) == NULL)
        return 0;

    Node* prev_node = NULL;
    Node* curr_node = NULL;

    // Traverse till desired Node by decrementing pos till it reaches 1
    for (curr_node = (*ptr_first); curr_node != NULL && pos > 1; prev_node =
            curr_node, curr_node = curr_node->next, --pos)
        ;

    // curr_node can only be NULL if pos is bigger than list length
    if (pos < 1 || curr_node == NULL)
    {
        printf("Invalid Position!\n");
        return 1;
    }
    else
    {
        // If pos is 1
        if (prev_node == NULL)
            (*ptr_first) = curr_node->next;
        else
            prev_node->next = curr_node->next;
        free(curr_node);
        return 0;
    }

    return 1;
}

Node* reverse_list(Node* prev, Node* curr)
{
    Node* next = NULL;

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

    return reverse_list(curr, next);
}

Node* concatenate_lists(Node* list1, Node* list2)
{
    Node* curr_node = NULL;

    for (curr_node = list1; curr_node != NULL; curr_node = curr_node->next)
        if (curr_node->next == NULL)
        {
            curr_node->next = list2;
            return list1;
        }

    return NULL;
}

int display_list(char* msg, Node* curr_node)
{
    printf("%s", msg);
    for (; curr_node != NULL; curr_node = curr_node->next)
    {
        printf(TYPE_FORMAT, curr_node->value);
        printf("->");
    }
    printf("NULL\n");

    return 0;
}
