#include <stdio.h>
#include <string.h>

typedef struct Man
{
	char* name;
	int age;
} Man;

void print(Man *, int, char *);
void printUsage();
char getArg(int,char**,char*,char*);
void sort(Man *, int, void (*)(Man *, int, char (*)(Man, Man)), char (*)(Man,Man));
void bubbleSort(Man *, int, char (*)(Man, Man));
void selectionSort(Man *, int, char (*)(Man, Man));
char ageAsc(Man, Man);
char ageDes(Man, Man);
char nameAsc(Man, Man);
char nameDes(Man, Man);

#define BUBBLESORT "BUBBLE"
#define SELECTIONSORT "SELECTION"
#define NAME "NAME"
#define AGE "AGE"
#define ASCENDING "ASCENDING"
#define DESCENDING "DESCENDING"

#define MAXLEN 1024

int main(int argn, char** args)
{
	Man list[] = {"c",2,"a",3,"b",1};
	int n = sizeof(list) / sizeof(Man);
	print(list,n,"Initial: ");

	if (argn != 4)
		printUsage();
	else
	{
		void (*sa)(Man* ,int,char (*comp)(Man, Man))=selectionSort;
		char (*cf)(Man, Man)=nameDes;

		char argStr[MAXLEN];

		if(getArg(argn,args,"-alg",argStr))
		{
			if (strcmp(argStr,BUBBLESORT)==0)
			{
				sa = bubbleSort;
				printf("Using Bubble Sort\n");
			}
			else if (strcmp(argStr,SELECTIONSORT)==0)
			{
				sa = selectionSort;
				printf("Using Selection Sort\n");
			}
			else
				printUsage();
		}
		else
			printUsage();

		if(getArg(argn,args,"-sort",argStr))
		{
			if (strcmp(argStr,AGE)==0)
			{
				printf("Sorting By Age\n");

				if(getArg(argn,args,"-order",argStr))
				{
					if (strcmp(argStr,ASCENDING)==0)
					{
						printf("Sorting In Ascending Order\n");
						cf = ageAsc;
					}
					else if (strcmp(argStr,DESCENDING)==0)
					{
						printf("Sorting In Descending Order\n");
						cf = ageDes;
					}
					else
						printUsage();
				}
				else
					printUsage();
			}
			else if (strcmp(argStr,NAME)==0)
			{
				printf("Sorting By Name\n");

				if(getArg(argn,args,"-order",argStr))
				{
					if (strcmp(argStr,ASCENDING)==0)
					{
						printf("Sorting In Ascending Order\n");
						cf = nameAsc;
					}
					else if (strcmp(argStr,DESCENDING)==0)
					{
						printf("Sorting In Descending Order\n");
						cf = nameDes;
					}
					else
						printUsage();
				}
				else
					printUsage();
			}
			else
				printUsage();
		}
		else
			printUsage();

		sort(list,n,sa,cf);
		print(list,n,"\nSorted: ");
	}

	return 0;
}

// Printing Array
void print(Man *ar, int n, char *msg)
{
	int i = 0;
	printf("%s\n",msg);
	for (i=0;i<n;++i)
	{
		printf("%s\t%d\n",ar[i].name,ar[i].age);
	}
	printf("\n");
}

// Program Usage
void printUsage()
{
	printf("USAGE: $ ./lab0 <options>\n");
	printf("All three options are mandatory.\n\n");
	printf("OPTIONS:\n");
	printf("-alg<txt>\t<txt>:BUBBLE or SELECTION\n");
	printf("-sort<txt>\t<txt>:AGE or NAME\n");
	printf("-order<txt>\t<txt>:ASCENDING or DESCENDING\n");

}

// Parsing CLA
char getArg(int argn,char** args,char* op,char* buf)
{
	--argn;

	int i=0;
	char* argStr;
	int opLen = strlen(op);
	char chk = 0;

	for (;argn>0;--argn)
	{
		chk = 0;
		argStr = args[argn];
		for (i=opLen-1;i>=0;--i)
		{
			if (op[i] != argStr[i])
			{
				chk=1;
				break;
			}
		}

		if (chk == 0)
		{
			strcpy(buf,argStr+opLen);
			return 1;
		}
	}

	return 0;
}

// Sorting Functions
void sort(Man *ar, int len, void (*sortAlg)(Man *, int, char (*)(Man, Man)), char (*comp)(Man,Man))
{
	sortAlg(ar,len,comp);
}

void bubbleSort(Man *ar, int len, char (*comp)(Man, Man))
{
	// printf("bubbleSort\n");
	Man tmp;
	int i = 0, j = 0;
	for (i=len-1;i>0;--i)
	{
		for (j=0;j<i;++j)
		{
			if (comp(ar[j],ar[j+1]))
			{
				tmp = ar[j];
				ar[j] = ar[j+1];
				ar[j+1] = tmp;
			}
		}
	}
}

void selectionSort(Man *ar, int len, char (*comp)(Man, Man))
{
	// printf("selectionSort\n");
	Man tmp;
	int i = 0, j = 0, mx = 0;
	for (i=len-1;i>0;--i)
	{
		mx = i;
		for (j=0;j<=i;++j)
		{
			if (comp(ar[j],ar[mx]))
				mx = j;
		}
		tmp = ar[i];
		ar[i] = ar[mx];
		ar[mx] = tmp;
	}
}

// Comparison Functions
char ageAsc(Man a, Man b)
{
	// printf("ageAsc\n");
	if (a.age > b.age)
		return 1;
	return 0;
}

char ageDes(Man a, Man b)
{
	// printf("ageDes\n");
	if (a.age < b.age)
		return 1;
	return 0;
}

char nameAsc(Man a, Man b)
{
	// printf("nameAsc\n");
	if (strcmp(a.name,b.name)>0)
		return 1;
	return 0;
}

char nameDes(Man a, Man b)
{
	// printf("nameDes\n");
	if (strcmp(a.name,b.name)<0)
		return 1;
	return 0;
}