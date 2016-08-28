#include "include/DoublyLinkedList.h"

#define DLL 'd'

int check_for_help(char**, int);
void run_all_tests();
void run_tests(char**, int);
void print_help();

void test_doubly_ll();

int main(int argl, char** argv) {
	if (check_for_help(argv + 1, argl - 1)) {
		if (argl == 1)
			run_all_tests();
		else
			run_tests(argv + 1, argl - 1);
	}
	return 0;
}

int check_for_help(char** args, int no_of_args) {
	if (no_of_args > 0) {
		int i = 0;
		char* tmp = "--help";
		for (i = 0; i < no_of_args; ++i)
			if (strcmp(args[i], tmp) == 0) {
				print_help();
				return 0;
			}
	}
	return 1;
}

void run_all_tests() {
	test_doubly_ll();
	printf("\n\n");

}

void run_tests(char** args, int no_of_args) {
	int i = 0;
	for (i = 0; i < no_of_args; ++i) {
		if (args[i][1] == DLL)
			test_doubly_ll();
		if (i != no_of_args - 1)
			printf("\n\n");
	}
}

void print_help() {
	printf(
			"USAGE: $ ./test <options>\nIf no options are provided, then all tests will execute.\n\n");
	printf("OPTIONS:\n");
	printf("-%c  :  Test Doubly Linked List.\n", DLL);
}

void test_doubly_ll() {
	printf("\tTesting Doubly Linked List Implementation...\n\n");

	int values1[] = { 101, 100, 99, 99, 98, 97, 96, 95 };

	Node* list1 = dll_create_from_array(values1,
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

	DLL_ELEM_TYPE v3 = 0;
	int pos1 = 3;
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

	printf("\nReversing list1.\n");
	list1 = dll_reverse_list(list1);
	dll_display_list("list1: ", list1);
}

