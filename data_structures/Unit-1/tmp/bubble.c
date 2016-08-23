#include <stdio.h>
#include <string.h>

#define SIZE 4

typedef struct Student{

        int marks;
        int age;
        char name[10];
}Student; 

Student s[SIZE] = { {1,22,"aaa"}, {2,13,"bbb"}, {3,44,"ccc"}, {4,14,"ddd"} };

void bubble(int(*f)(int, int), int(*para)(Student, Student, int(*f)(int, int))){
	int i, j;
	for(i = 0; i < SIZE; i++){
		for(j = 0; j < SIZE-i-1; j++){
			if(para(s[j], s[j+1], f)){
				Student temp = s[j];
				s[j] = s[j+1];
				s[j+1] = temp;
			}
		}
	}
}


int greater(int x, int y){

	return x > y ? 1 : 0;
}

int smaller(int x, int y){

	return x < y ? 1 : 0;
}

int byAge(Student s1, Student s2, int(*f)(int, int)){
	if(f(s1.age, s2.age))
		return 1;
	else 
		return 0;
}

int byMarks(Student s1, Student s2, int(*f)(int, int)){
	if(f(s1.marks, s2.marks))
		return 1;
	else 
		return 0;
}

int byName(Student s1, Student s2, int(*f)(int, int)){

	if(f == smaller){
		if(strcmp(s1.name, s2.name) < 0)
			return 1;
		else 
			return 0;
	}

	if(f == greater){
		if(strcmp(s1.name, s2.name) > 0)
			return 1;
		else 
			return 0;
	}
}

//int (*p)(int(*f)(int, int), Student, Student)

int getOptions(){

	int op;
	printf("\n\n\nEnter Parameter: ");
	printf("\n1. Age");
	printf("\n2. Marks");
	printf("\n3. Name");
	printf("\n\nEnter choice: ");
	scanf("%d", &op);
	return op;
}


void inter(int(*f)(int, int)){
	
	int options;
	options = getOptions();
	switch (options){
		case 1:{
			bubble(f, byAge); break;
		}

		case 2:{
			bubble(f, byMarks); break;
		}
		
		case 3:{
			bubble(f, byName); break;
		}
	}

}

int main_menu(){
	int choice;

	printf("\n<-----------MAIN MENU----------->");
	printf("\n1. Descending Order");
	printf("\n2. Ascending Order");
	printf("\n\nEnter choice: ");
	scanf("%d", &choice);

	switch(choice){
		case 1: inter(smaller); break;
		case 2:{ inter (greater); break;}
	}
}
	

int main(){

	main_menu();
	print();
}

void print(){
	int i;
	printf("\n\nData: \n\n");
	for(i = 0; i < SIZE; i++){
		printf("%d %d %s\n", s[i].marks, s[i].age, s[i].name);
	}	        
}        


