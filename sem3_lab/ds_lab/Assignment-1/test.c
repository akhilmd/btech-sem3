#include <stdio.h>
#include "./include/ArrayList.h"

void test_array_list();

int main()
{
    test_array_list();
    return 0;
}

void test_array_list()
{
    ArrayList* alist = al_init(4);

    // Display when no elements
    al_display(alist, "Display when no elements: ");

    // Insert at the end
    alist = al_insert_end(alist, 99);
    al_display(alist, "Insert at the end: ");

    // Insert at the front
    alist = al_insert_front(alist, 97);
    alist = al_insert_front(alist, 96);
    al_display(alist, "Insert at the front: ");

    // Insert in invalid position
    alist = al_insert_at(alist, 1000, 10);
    alist = al_insert_at(alist, 1000, -1);

    // Insert at a specific position
    alist = al_insert_at(alist, 98, 2);
    al_display(alist, "Insert at a specific position: ");

    // Insert when array is full
    alist = al_insert_end(alist, 1001);
    alist = al_insert_front(alist, 1002);
    alist = al_insert_at(alist, 1003, 1);

    // Reverse the data in list
    alist = al_reverse(alist);
    al_display(alist, "Reverse the data in list: ");

    // Delete based on element value
    alist = al_delete_with_val(alist, 1004);
    alist = al_delete_with_val(alist, 97);
    al_display(alist, "Delete based on element value: ");

    // Delete at an invalid position
    alist = al_delete_at(alist, 10);
    alist = al_delete_at(alist, -1);

    // Delete at a specific position
    alist = al_delete_at(alist, 2);
    al_display(alist, "Delete at a specific position: ");

    // Delete at the front
    alist = al_delete_front(alist);
    al_display(alist, "Delete at the front: ");

    // Delete at the end
    alist = al_delete_end(alist);
    al_display(alist, "Delete at the end: ");

    // Delete when list is empty
    alist = al_delete_end(alist);
    alist = al_delete_front(alist);
    alist = al_delete_at(alist, 1);
}
