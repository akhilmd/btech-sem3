#include "../include/DoublyLinkedList.h"

Node* dll_create_from_array(DLL_ELEM_TYPE* ar, int n) {
	Node* first_node = NULL;

	int i = 0;

	for (i = 0; i < n; ++i)
		first_node = dll_insert_end(first_node, ar[i]);

	return first_node;
}

Node *dll_insert_start(Node *head_ref, DLL_ELEM_TYPE element) {

	Node *temp;
	temp = (Node*) malloc(sizeof(Node));
	temp->data = element;
	temp->prev = NULL;
	temp->next = NULL;
	if (head_ref == NULL)
		return temp;
	else {

		temp->next = head_ref;
		head_ref->prev = temp;
		head_ref = temp;
		return head_ref;
	}
}

void dll_display_list(char* msg, Node *q) {

	printf("%s", msg);
	if (q == NULL)
		printf("Empty List\n");

	else {
		printf("\n\n");

		while (q != NULL) {
			printf("%d -> ", q->data);
			q = q->next;
		}

		printf("\n\n");
	}
}

Node *dll_insert_end(Node *head_ref, DLL_ELEM_TYPE element) {

	Node *temp, *q;
	temp = (Node*) malloc(sizeof(Node));
	temp->data = element;
	temp->next = NULL;
	temp->prev = NULL;

	if (head_ref == NULL)
		head_ref = temp;
	else {
		q = head_ref;
		while (q->next != NULL)
			q = q->next;
		q->next = temp;
		temp->prev = q;
	}

	return head_ref;
}

Node *dll_delete_element(Node *head_ref, DLL_ELEM_TYPE element) {
	Node *q;
	q = head_ref;

	while ((q != NULL) && (q->data != element))
		q = q->next;

	if (q != NULL) {
		// if only one node in the list
		if ((q->prev == NULL) && (q->next == NULL))
			head_ref = NULL; //make first NULL
		else if (q->prev == NULL) //first node
				{
			head_ref = q->next;
			(head_ref)->prev = NULL;
		} else if (q->next == NULL) //last node
			q->prev->next = NULL;
		else //middle
		{
			q->prev->next = q->next;
			q->next->prev = q->prev;
		}
		free(q);
	} else
		printf("NODE not found\n");

	return head_ref;

}

Node *dll_delete_start(Node *head_ref) {
	if (head_ref == NULL)
		printf("Underflow!!");
	else {
		Node *temp = head_ref;
		head_ref = head_ref->next;
		free(temp);
		head_ref->prev = NULL;
		printf("\nDeleted!\n");
	}

	return head_ref;
}

Node *dll_delete_end(Node *head_ref) {
	if (head_ref == NULL)
		printf("Underflow!!");
	else {
		Node *q = head_ref;
		while (q->next->next != NULL)
			q = q->next;

		Node *temp = q->next;
		q->next = NULL;
		free(temp);
		printf("\nDeleted!\n");
	}

	return head_ref;
}

Node *dll_insert_at(Node *head_ref, DLL_ELEM_TYPE element, int pos) {
	int i = 0;
	Node *q, *temp;
	q = head_ref;

	temp = (Node*) malloc(sizeof(Node));
	temp->data = element;
	temp->next = NULL;
	temp->prev = NULL;

	if (pos == 1)
		dll_insert_start(head_ref, element);

	else {

		for (i = 1; (q->next != NULL) && (i < pos); ++i)
			q = q->next;

		if (i == pos) //insert in middle before q;
				{
			q->prev->next = temp;
			temp->prev = q->prev;
			temp->next = q;
			q->prev = temp;
		} else if (i == pos - 1) //insert end
				{
			q->next = temp;
			temp->prev = q;
		} else
			printf("Invalid position");
	}

	return head_ref;

}

Node* dll_reverse_list(Node *head_ref) {
	Node *temp = NULL;
	Node *current = head_ref;

	while (current != NULL) {
		temp = current->prev;
		current->prev = current->next;
		current->next = temp;
		current = current->prev;
	}

	if (temp != NULL)
		head_ref = temp->prev;

	return head_ref;
}
