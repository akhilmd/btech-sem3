#include "../include/SinglyLinkedList.h"

Node* create_from_array(TYPE* ar, int n)
{
    Node* first_node = NULL;

    int i = 0;

    for (i=0;i<n;++i)
    {
        insert_end(&first_node, ar[i]);
    }

    return first_node;
}

int insert_end(Node** ptr_first, TYPE in_val)
{
    Node* new_node = (Node*) malloc(sizeof(Node));

    if (new_node == NULL)
    {
        printf("ERROR!\n");
        return 1;
    }

    new_node->value = in_val;
    new_node->next = NULL;

    if ((*ptr_first) == NULL)
    {
        (*ptr_first) = new_node;
        return 0;
    }
    else
    {
        Node* i_node = (*ptr_first);

        for (; i_node != NULL; i_node = i_node->next)
            if (i_node->next == NULL)
            {
                i_node->next = new_node;
                return 0;
            }
    }
}

int insert_start(Node** ptr_first, TYPE in_val)
{
    Node* new_node = (Node*) malloc(sizeof(Node));

    if (new_node == NULL)
    {
        printf("ERROR!\n");
        return 1;
    }

    new_node->value = in_val;
    new_node->next = (*ptr_first);
    (*ptr_first) = new_node;

    return 0;
}

int insert_at(Node** ptr_first, TYPE in_val, int pos)
{
    if (pos == 1)
        return insert_start(ptr_first, in_val);

    Node* new_node = (Node*) malloc(sizeof(Node));
    Node* i_node = NULL;

    if (new_node == NULL)
    {
        printf("ERROR!\n");
        return 1;
    }

    new_node->value = in_val;
    new_node->next = NULL;

    for (i_node = (*ptr_first), --pos; i_node != NULL && pos > 0; i_node =
            i_node->next, --pos)
    {
        if (pos == 1)
        {
            new_node->next = i_node->next;
            i_node->next = new_node;
            return 0;
        }
    }

    printf("Invalid Position!\n");
    return 1;
}

int delete_start(Node** ptr_first)
{
    Node *to_be_freed = *ptr_first;

    (*ptr_first) = (*ptr_first)->next;
    free(to_be_freed);

    return 0;
}

int delete_end(Node** ptr_first)
{
    if ((*ptr_first) == NULL)
        return 0;

    if ((*ptr_first)->next == NULL)
    {
        return delete_start(ptr_first);
    }

    Node* i_node = NULL;

    for (i_node = (*ptr_first); i_node != NULL; i_node = i_node->next)
        if (i_node->next->next == NULL)
        {
            free(i_node->next);
            i_node->next = NULL;
            return 0;
        }

    return 1;
}

int delete_at(Node** ptr_first, int pos)
{
    if (pos == 1)
        return delete_start(ptr_first);

    Node* i_node = NULL;

    for (i_node = (*ptr_first), --pos;i_node != NULL && pos > 0; i_node = i_node->next, --pos)
    {
        if (pos == 1)
        {
            Node *to_be_freed = i_node->next;
            i_node->next = i_node->next->next;
            free(to_be_freed);
            return 0;
        }
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

    if (next == NULL)
        return curr;

    return reverse_list(curr, next);
}

Node* concatenate_lists(Node* list1, Node* list2)
{
    Node* i_node = NULL;

    for (i_node = list1;i_node != NULL;i_node = i_node->next)
    {
        if (i_node->next == NULL)
        {
            i_node->next = list2;
            return list1;
        }
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
