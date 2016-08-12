#include <stdio.h>
#include <stdlib.h>

#define TYPE_FORMAT "%d"

typedef int TYPE;

typedef struct Node
{
	TYPE value;
	struct Node* next;
} Node;

char insert_end(Node**, TYPE);
char insert_start(Node**, TYPE);
Node* reverse_list(Node*, Node*, Node*);
char display_list(char*, Node*);

int main()
{
	Node* first_node = NULL;

	insert_end(&first_node, 4);
	insert_end(&first_node, 5);
	insert_end(&first_node, 6);
	insert_start(&first_node, 3);
	insert_start(&first_node, 2);
	insert_start(&first_node, 1);

	display_list("Initial: ", first_node);
	first_node = reverse_list(NULL, first_node, first_node->next);
	display_list("Reversed: ", first_node);

	return 0;
}

char insert_end(Node** ptr_first, TYPE in_val)
{
	Node* new_node = (Node*) malloc(sizeof(Node));

	if (new_node == NULL)
	{
		printf("ERROR!\n");
		return 0;
	}

	new_node->value = in_val;
	new_node->next = NULL;

	if ((*ptr_first) == NULL)
	{
		(*ptr_first) = new_node;
		return 1;
	}
	else
	{
		Node* i_node = (*ptr_first);

		for (;i_node != NULL;i_node = i_node->next)
			if (i_node->next == NULL)
			{
				i_node->next = new_node;
				return 1;
			}
	}
}

char insert_start(Node** ptr_first, TYPE in_val)
{
	Node* new_node = (Node*) malloc(sizeof(Node));

	if (new_node == NULL)
	{
		printf("ERROR!\n");
		return 0;
	}

	new_node->value = in_val;
	new_node->next = (*ptr_first);
	(*ptr_first) = new_node;

	return 1;
}

Node* reverse_list(Node* prev, Node* curr, Node* next)
{
	curr->next = prev;

	if (next == NULL)
		return curr;

	return reverse_list(curr, next, next->next);
}

char display_list(char* msg, Node* curr_node)
{
	printf("%s",msg);
	for (;curr_node != NULL;curr_node = curr_node->next)
	{
		printf(TYPE_FORMAT,curr_node->value);
		printf("->");
	}
	printf("NULL\n");

	return 1;
}