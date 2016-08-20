#include <stdio.h>
#include<stdlib.h>


typedef struct Array{
	int size;
	int count;
	int *a;
}Array;

void insertFirst(Array**, int);
void insertLast(Array**, int);
void delete(Array**, int);

void display(Array*);
void reverse(Array**, int, int);
void insertPos(int, int, Array **);

int main(){
	
	int choice, element, pos;
	Array *head = (Array*)malloc(sizeof(Array));

	printf("Enter size of array: ");
	scanf("%d", &head->size);
	head->count = 0;
	
	head->a = (int*)malloc(sizeof(int) * head->size);
	
	while (1) {
		display(head);
		printf("<------------Main Menu------------>");
		printf("\n1. Insert front\n");
		printf("\n2. Insert end\n");
		printf("\n3. Delete an element\n");
		printf("\n4. Insert at a position\n");
		printf("\n5. Reverse the List\n");
		printf("\n6. Exit");
		printf("\n\nEnter Choice: ");
		scanf("%d", &choice);
		switch (choice) {
		case 1:
			printf("Enter element to be added: ");
			scanf("%d", &element);
			insertFirst(&head, element);
			break;
		case 2:
			printf("Enter element to be added: ");
			scanf("%d", &element);
			insertLast(&head, element);
			break;
		case 3:
			printf("Enter element to be deleted: ");
			scanf("%d", &element);
			delete(&head, element);
			break;
		case 4:
			printf("Enter the position and element(pos ele): ");
			scanf("%d %d", &pos, &element);
			insertPos(element, pos, &head);
			break;
		case 5:
			reverse(&head, 0,  head->count-1);
			break;
		case 6:
			exit(0);
		}
	}

}

void insertFirst(Array **head, int element){
	
	if((*head)->count == 0){
		(*head)->a[(*head)->count] = element;
		(*head)->count++;
	}
	
	else{
		if((*head)->count >= (*head)->size)
			printf("Overflow!!");
		else{
			int i = (*head)->size;
			while(i >= 0)
				(*head)->a[i+1] = (*head)->a[i--];
			(*head)->a[0] = element;
			(*head)->count++;
		}
	}
}

void display(Array *q) {
	if (q == NULL)
		printf("Empty List\n");
	else {
		printf("\n\n");
		int i = 0;
		while (i < q->count) 
			printf("%d -> ", q->a[i++]);
		
		printf("\n\n");
	}
}

void insertLast(Array** head, int element){
	
	if((*head)->count == 0){
		(*head)->a[(*head)->count] = element;
		(*head)->count++;
	}
	
	else{
		if((*head)->count >= (*head)->size)
			printf("Overflow!!");
		else{
			(*head)->a[(*head)->count] = element;
			(*head)->count++;
		}
		
	}
	
}

void delete(Array** head, int element){
	
	if((*head)->count == 0){
		printf("Underflow!!");
		return;
	}
	
	else{
		int i = 0;
		while(i < (*head)->count && (*head)->a[i]!=element)
			i++;
		if(i == (*head)->count){
			printf("Invalid item!!");
			return;
		}
		else{
			while(i < (*head)->count-1){
				(*head)->a[i] = (*head)->a[i+1];
				i++;
			}
			(*head)->count--;
		}
	}
}

void reverse(Array** head, int start, int end){
	
	if(start > end)
		return;
	else{
		int temp = (*head)->a[start];
		(*head)->a[start] = (*head)->a[end];
		(*head)->a[end] = temp;
		reverse(head, start + 1, end - 1);
	}
}

void insertPos(int element, int pos, Array **head){
	if(pos < 0 || pos > (*head)->count || (*head)->count >= (*head)->size){
		printf("Invalid Position!!");
		return;
	}
	
	else{
		int i = (*head)->count-1;
		while(i >= pos){
			(*head)->a[i+1] = (*head)->a[i--];
		}
		
		(*head)->a[pos] = element;
		(*head)->count++;
	}
}
