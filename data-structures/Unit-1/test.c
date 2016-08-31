#include "include/SinglyLinkedList.h"
#include "include/Recursion.h"
#include "include/PointersArrays.h"
#include "include/DoublyLinkedList.h"

#include <string.h>

#define REC 'r'
#define SLL 's'
#define PA 'p'
#define DLL 'd'

int check_for_help(char**, int);
void run_all_tests();
void run_tests(char**, int);
void print_help();

void test_rec();
void test_singly_ll();
void test_pointers_arrays();
void test_doubly_ll();

int main(int argl, char** argv)
{
    if (check_for_help(argv + 1, argl - 1))
    {
        if (argl == 1)
            run_all_tests();
        else
            run_tests(argv + 1, argl - 1);
    }
    return 0;
}

int check_for_help(char** args, int no_of_args)
{
    if (no_of_args > 0)
    {
        int i = 0;
        char* tmp = "--help";
        for (i = 0; i < no_of_args; ++i)
            if (strcmp(args[i], tmp) == 0)
            {
                print_help();
                return 0;
            }
    }
    return 1;
}

void run_all_tests()
{
    test_rec();
    printf("\n\n");
    test_singly_ll();
    printf("\n\n");
    test_pointers_arrays();
    printf("\n\n");
    test_doubly_ll();
}

void run_tests(char** args, int no_of_args)
{
    int i = 0;
    for (i = 0; i < no_of_args; ++i)
    {
        if (args[i][1] == REC)
            test_rec();
        else if (args[i][1] == SLL)
            test_singly_ll();
        else if (args[i][1] == PA)
            test_pointers_arrays();
        else if (args[i][1] == DLL)
            test_doubly_ll();

        if (i != no_of_args - 1)
            printf("\n\n");
    }
}

void print_help()
{
    printf(
            "USAGE: $ ./test <options>\nIf no options are provided, then all tests will execute.\n\n");
    printf("OPTIONS:\n");
    printf("-%c  :  Test Recursion Algorithms.\n", REC);
    printf("-%c  :  Test Singly Linked List Implementation.\n", SLL);
    printf("-%c  :  Test Pointers and Arrays.\n", PA);
    printf("-%c  :  Test Doubly Linked List Implementation.\n", DLL);
}

void test_singly_ll()
{
    printf("\tTesting Singly Linked List Implementation...\n\n");

    SLL_ELEM_TYPE values1[] =
    { 1, 2, 4, 5 };
    SLL_ELEM_TYPE values2[] =
    { 101, 100, 99, 99, 98, 97, 96, 95 };

    SLLNode* list1 = sll_create_from_array(values1,
            sizeof(values1) / sizeof(SLL_ELEM_TYPE));
    SLLNode* list2 = sll_create_from_array(values2,
            sizeof(values2) / sizeof(SLL_ELEM_TYPE));

    sll_display_list("list1: ", list1);
    sll_display_list("list2: ", list2);

    SLL_ELEM_TYPE v1 = 0;
    printf("\nInserting %d to start of list1.\n", v1);
    list1 = sll_insert_start(list1, v1);
    sll_display_list("list1: ", list1);

    SLL_ELEM_TYPE v2 = 6;
    printf("\nInserting %d to end of list1.\n", v2);
    list1 = sll_insert_end(list1, v2);
    sll_display_list("list1: ", list1);

    SLL_ELEM_TYPE v3 = 3;
    int pos1 = 4;
    printf("\nInserting %d in position %d of list1.\n", v3, pos1);
    list1 = sll_insert_at(list1, v3, pos1);
    sll_display_list("list1: ", list1);

    SLL_ELEM_TYPE v4 = 98;
    printf("\nDeleting element %d of list2.\n", v4);
    list2 = sll_delete_element(list2, v4);
    sll_display_list("list2: ", list2);

    printf("\nDeleting start of list2.\n");
    list2 = sll_delete_start(list2);
    sll_display_list("list2: ", list2);

    printf("\nDeleting end of list2.\n");
    list2 = sll_delete_end(list2);
    sll_display_list("list2: ", list2);

    int pos2 = 2;
    printf("\nDeleting node in position %d of list2.\n", pos2);
    list2 = sll_delete_at(list2, pos2);
    sll_display_list("list2: ", list2);

    printf("\nReversing list2.\n");
    list2 = sll_reverse_list(NULL, list2);
    sll_display_list("list2: ", list2);

    printf("\nConcatenating list1 and list2.\n");
    SLLNode* list12 = sll_concatenate_lists(list1, list2);
    sll_display_list("list12: ", list12);
}

void test_rec()
{
    printf("\tTesting Recursion Algorithms...\n\n");

    long num = 20;
    printf("factorial of %ld = %ld\n", num, fact(num));

    int len = 10000;
    int i = 0;

    int numbers[len];

    for (i = 0; i < len; ++i)
        numbers[i] = i + 1;

    printf("sum of array = %d\n", sumArray(numbers, len));
    printf("largest in array = %d\n", largest(numbers, len));
    printf("largest in array = %d\n", largest2(numbers, 0, len - 1));

    int big_num = 203041;
    printf("sum of digits of %d = %d\n", big_num, sumOfDigits(big_num));
}

void test_pointers_arrays()
{
    printf("\tTesting Pointers and Arrays...\n\n");
    test_pa();
}

void test_doubly_ll()
{
    printf("\tTesting Doubly Linked List Implementation...\n\n");

    int values1[] =
    { 101, 100, 99, 9999, 98, 97, 96, 95 };

    DLLNode* list1 = dll_create_from_array(values1,
            sizeof(values1) / sizeof(DLL_ELEM_TYPE));

    dll_display_list("list1: ", list1);

    DLL_ELEM_TYPE v1 = 2;
    printf("\nInserting %d to start of list1.\n", v1);
    list1 = dll_insert_start(list1, v1);
    dll_display_list("list1: ", list1);

    DLL_ELEM_TYPE v2 = 6;
    printf("\nInserting %d to end of list1.\n", v2);
    list1 = dll_insert_end(list1, v2);
    dll_display_list("list1: ", list1);

    DLL_ELEM_TYPE v3 = -10001;
    int pos1 = 11;
    printf("\nInserting %d in position %d of list1.\n", v3, pos1);
    list1 = dll_insert_at(list1, v3, pos1);
    dll_display_list("list1: ", list1);

    DLL_ELEM_TYPE v4 = 98;
    printf("\nDeleting element %d of list1.\n", v4);
    list1 = dll_delete_element(list1, v4);
    dll_display_list("list1: ", list1);

    printf("\nDeleting start of list1.\n");
    list1 = dll_delete_start(list1);
    dll_display_list("list1: ", list1);

    printf("\nDeleting end of list1.\n");
    list1 = dll_delete_end(list1);
    dll_display_list("list1: ", list1);

    int pos2 = 5;
    printf("\nDeleting element in position %d of list1.\n", pos2);
    list1 = dll_delete_at(list1, pos2);
    dll_display_list("list1: ", list1);

    printf("\nReversing list1.\n");
    list1 = dll_reverse_list(list1);
    dll_display_list("list1: ", list1);
}
