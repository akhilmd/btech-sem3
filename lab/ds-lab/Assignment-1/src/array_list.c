#include <stdio.h>
#include <stdlib.h>
#include "../include/ArrayList.h"

ArrayList* al_init(int mx_len)
{
    // Allocate space for list variable and initialize all attributes.
    ArrayList* new_list = (ArrayList*) malloc(sizeof(ArrayList));
    new_list->length = 0;
    new_list->max_length = mx_len;
    new_list->data = NULL;
    return new_list;
}

void al_insert_end(ArrayList* list, AL_ELEM_TYPE new_val)
{
    if (list->length < list->max_length)
    {
        // Increase data array size by one and insert new element
        ++(list->length);
        list->data = (AL_ELEM_TYPE*) realloc(list->data, list->length * sizeof(AL_ELEM_TYPE));
        list->data[list->length - 1] = new_val;
    }
    else
        printf("al_insert_end: List is full.\n");
}

void al_insert_front(ArrayList* list, AL_ELEM_TYPE new_val)
{
    if (list->length < list->max_length)
    {
        // Increase data array size by one and insert new element
        ++(list->length);
        list->data = (AL_ELEM_TYPE*) realloc(list->data, list->length * sizeof(AL_ELEM_TYPE));

        int i = 0;

        // Shift existing elements to the right
        for (i = (list->length - 1); i > 0; --i)
            list->data[i] = list->data[i - 1];

        list->data[0] = new_val;
    }
    else
        printf("al_insert_front: List is full.\n");
}

void al_insert_at(ArrayList* list, AL_ELEM_TYPE new_val, int position)
{
    // position is 1-based
    if (position < 1 || position > list->length)
    {
        printf("al_insert_at: Invalid position.\n");
        return;
    }

    if (list->length < list->max_length)
    {
        // Increase data array size by one and insert new element
        ++(list->length);
        list->data = (AL_ELEM_TYPE*) realloc(list->data, list->length * sizeof(AL_ELEM_TYPE));

        int i = 0;

        // Shift elements after position to the right
        for (i = (list->length - 1); i >= position; --i)
            list->data[i] = list->data[i - 1];
        list->data[position - 1] = new_val;
    }
    else
        printf("al_insert_at: List is full.\n");
}

void al_delete_front(ArrayList* list)
{
    if (list->length > 0)
    {
        int i = 0;

        // Shift elements to the left
        for (i = 0; i < list->length; ++i)
            list->data[i] = list->data[i + 1];

        // Decrease size of data array to remove last element
        --(list->length);
        list->data = (AL_ELEM_TYPE*) realloc(list->data, list->length * sizeof(AL_ELEM_TYPE));

    }
    else
        printf("al_delete_front: List is empty.\n");
}

void al_delete_end(ArrayList* list)
{
    if (list->length > 0)
    {
        // Decrease size of data array to remove last element
        --(list->length);
        list->data = (AL_ELEM_TYPE*) realloc(list->data, list->length * sizeof(AL_ELEM_TYPE));
    }
    else
        printf("al_delete_end: List is empty.\n");
}

void al_delete_at(ArrayList* list, int position)
{
    // position is 1-based
    if (position < 1 || position > list->length)
    {
        printf("al_delete_at: Invalid position.\n");
        return;
    }

    if (list->length > 0)
    {
        int i = 0;

        // Shift elements after position to the left
        for (i = (position - 1); i < list->length; ++i)
            list->data[i] = list->data[i + 1];

        // Decrease size of data array to remove last element
        --(list->length);
        list->data = (AL_ELEM_TYPE*) realloc(list->data, list->length * sizeof(AL_ELEM_TYPE));
    }
    else
        printf("al_delete_at: List is empty.\n");
}

void al_delete_with_val(ArrayList* list, AL_ELEM_TYPE val)
{
    if (list->length > 0)
    {
        int i = 0;

        // Traverse till element with correct value is found
        for (i = 0; i < list->length && list->data[i] != val; ++i)
            ;

        // Delete at the position where the traversal stopped in previous step
        if (i >= list->length)
            printf("al_delete_with_val: Element with value %d not found.\n",
                    val);
        else
            al_delete_at(list, i + 1);
    }
    else
        printf("al_delete_with_val: List is empty.\n");
}

void al_reverse(ArrayList* list)
{
    int i = 0, tmp = 0;

    // Swap elements from the ends till the center is reached
    for (i = 0; i < (list->length / 2); ++i)
    {
        tmp = list->data[i];
        list->data[i] = list->data[list->length - 1 - i];
        list->data[list->length - 1 - i] = tmp;
    }
}

void al_display(ArrayList* list, char* msg)
{
    printf("%s", msg);

    if (list->length == 0)
    {
        printf("al_display: List is empty.\n");
        return;
    }

    int i = 0;

    for (i = 0; i < (list->length); ++i)
        printf("%d ", list->data[i]);
    printf("\n");
}
