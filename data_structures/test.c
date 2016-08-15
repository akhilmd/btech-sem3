#include "include/SinglyLinkedList.h"
#include <string.h>

int check_for_help(char**, int);
void run_all_tests();
void run_tests(char**, int);
void print_help();

void test_singly_ll();
void test_fact();

int main(int argl, char** argv)
{
    if (check_for_help(argv+1,argl-1))
    {
        if (argl == 1)
            run_all_tests();
        else
            run_tests(argv+1,argl-1);
    }
    return 0;
}

int check_for_help(char** args, int no_of_args)
{
    if (no_of_args>0)
    {
        int i = 0;
        char* tmp = "--help";
        for (i=0;i<no_of_args;++i)
            if (strcmp(args[i],tmp)==0)
            {
                print_help();
                return 0;
            }
    }
    return 1;
}

void run_all_tests()
{
    test_singly_ll();
    test_fact();
}

void run_tests(char** args, int no_of_args)
{
    int i = 0;
    for (i=0;i<no_of_args;++i)
    {
        printf("%c\n",args[i][0]);
    }
}

void print_help()
{
    printf("USAGE:\n\n");
}

void test_singly_ll()
{
    TYPE values1[] = {1,2,4,5};
    TYPE values2[] = {101,100,99,99,98,97,96,95};

    Node* list1 = create_from_array(values1, sizeof(values1)/sizeof(TYPE));
    Node* list2 = create_from_array(values2, sizeof(values2)/sizeof(TYPE));

    display_list("list1: ", list1);
    display_list("list2: ", list2);

    TYPE v1 = 0;
    printf("\nInserting %d to start of list1.\n", v1);
    insert_start(&list1, v1);
    display_list("list1: ", list1);

    TYPE v2 = 6;
    printf("\nInserting %d to end of list1.\n", v2);
    insert_end(&list1, v2);
    display_list("list1: ", list1);

    TYPE v3 = 3;
    int pos1 = 4;
    printf("\nInserting %d in position %d of list1.\n", v3, pos1);
    insert_at(&list1, v3, pos1);
    display_list("list1: ", list1);

    printf("\nDeleting start of list2.\n");
    delete_start(&list2);
    display_list("list2: ", list2);

    printf("\nDeleting end of list2.\n");
    delete_end(&list2);
    display_list("list2: ", list2);

    int pos2 = 2;
    printf("\nDeleting node in position %d of list2.\n", pos2);
    delete_at(&list2, pos2);
    display_list("list2: ", list2);

    printf("\nReversing list2.\n");
    list2 = reverse_list(NULL, list2);
    display_list("list2: ", list2);

    printf("\nConcatenating list1 and list2.\n");
    Node* list12 = concatenate_lists(list1,list2); 
    display_list("list12: ", list12);
}

void test_fact()
{
    printf("TBD\n");
}