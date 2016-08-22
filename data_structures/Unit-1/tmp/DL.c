#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
	struct Node *prev;	
	int data;
	struct Node *next;
} Node;

Node *insertFirst(Node*, int);
void display(Node*);
Node *insertLast(Node*, int);
Node *delete(Node*, int);
Node *deleteFirst(Node*);
Node *deleteLast(Node*);
Node *insertPos(int, int, Node *);
void mainMenu(Node*);

int main() {

	Node *head = (Node*) malloc(sizeof(Node));
    head = NULL;
	mainMenu(head);
}

void mainMenu(Node *head) {
	int choice, element, pos;
	while (1) {
		display(head);
		printf("<------------Main Menu------------>");
		printf("\n1. Insert Front\n");
		printf("\n2. Insert End\n");
		printf("\n3. Delete a node\n");
		printf("\n4. Delete First\n");
		printf("\n5. Delete Last\n");
		printf("\n6. Insert at a position\n");
		printf("\n7. Exit");
		printf("\n\nEnter Choice: ");
		scanf("%d", &choice);
		switch (choice) {
		case 1:
			printf("Enter element to be added: ");
			scanf("%d", &element);
			head = insertFirst(head, element);
			break;
		case 2:
			printf("Enter element to be added: ");
			scanf("%d", &element);
			head = insertLast(head, element);
			break;
		case 3:
			printf("Enter element to be deleted: ");
			scanf("%d", &element);
			head = delete(head, element);
			break;
		case 4:
			head = deleteFirst(head);
			break;
		case 5:
			head = deleteLast(head);
			break;
		case 6:
			printf("Enter the position and element(pos ele): ");
			scanf("%d %d", &pos, &element);
			head = insertPos(element, pos, head);
			break;
		case 7:
			exit(0);
		}
	}
}


Node *insertFirst(Node *head, int element) {
	
    Node *temp;
	temp = (Node*) malloc(sizeof(Node));
	temp->data = element;
    temp->prev = NULL;
    temp->next = NULL;
    if(head == NULL)
        return temp;
    else{
        head->prev = temp;
        temp->next = head;
        head = temp;
        return head;
    }
}

void display(Node *q) {
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

Node *insertLast(Node *head, int element) {

	Node *temp, *q;
	temp = (Node*) malloc(sizeof(Node));
	temp->data = element;
	temp->next = NULL;


	if (head == NULL)
		head = temp;
	else {
		q = head;
		while (q->next != NULL)
			q = q->next;
		q->next = temp;
        temp->prev = q;
	}


	return head;
}

Node *delete(Node *head, int element) {
	Node *q;
	q = head;

	while ((q != NULL) && (q->data != element))
		q = q->next;

	if (q == NULL)
		printf("Node not foud\n");
	else {

		if (q->prev == NULL)
			head = q->next;
		else
			q->prev->next = q->next;
		free(q);
	}

	return head;

}

Node *deleteFirst(Node *head) {
	if (head == NULL)
		printf("Underflow!!");
	else {
		Node *temp = head;
		head = head->next;
		free(temp);
		printf("\nDeleted!\n");
	}

	return head;
}



Node *deleteLast(Node *head) {
	if (head == NULL)
		printf("Underflow!!");
	else {
		Node *q = head;
		while (q->next->next != NULL)
			q = q->next;

		Node *temp = q->next;
		q->next = NULL;
		free(temp);
		printf("\nDeleted!\n");
	}

	return head;
}


Node *insertPos(int element, int pos, Node *head) {
	int i=0;
	Node *q, *temp;
	q = head;

	temp = (Node*) malloc(sizeof(Node));
	temp->data = element;
	temp->next = NULL;
    temp->prev = NULL;

    
	if (pos == 1) {
		temp->next = head;
		head = temp;
	} 
    else {

		for (i = 1; (q != NULL) && (i < pos); ++i) 
			q = q->next;

		if (q != NULL) {
			temp->next = q;
            temp->prev = q->prev;
			q->prev->next = temp;
            q->prev = temp;
            
		}

		else {
			if (i == pos){
				q->prev->next = temp;
                
            }
			else
				printf("\nInvalid position\n");
		}
	}

	return head;

}
