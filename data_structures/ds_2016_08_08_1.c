#include <stdio.h>
#include <stdlib.h>

void display(int (*s)[2], int il, int jl)
{
	int i=0,j=0;

	for (i=0;i<il;++i)
	{
		for (j=0;j<jl;++j)
			printf("%d ", s[i][j]);
		printf("\n");
	}
}

void try1()
{
	int nb_rows=5;
	int nb_cols = 2;

	int **ar2D = (int **) malloc(nb_rows*sizeof(int *));

	int i,j,k=1;

	for (i=0;i<nb_rows;++i)
	{
		ar2D[i] = (int *) malloc(nb_cols*sizeof(int));
	}

	for (i=0;i<nb_rows;++i)
		for (j=0;j<nb_cols;++j)
		{
			ar2D[i][j]=k;
			++k;
		}

	display(ar2D,nb_rows,nb_cols);

	// printf("%d\n", sizeof(ar2D));
}

void ptp()
{
	int a[2][2]={1,2,
				 3,4};

	display(a,2,2);

	printf("%d\n",sizeof((int **)a));

	// printf("main_cols=%lu\n",sizeof(s[0])/sizeof(int));
	// printf("main_rows=%lu\n",sizeof(s)/sizeof(s[0]));
	// display(s);

	// printf("a=%u\n", a);
	// printf("a[0]=%u\n", a[0]);
	// printf("&a[0][0]=%u\n", &a[0][0]);
	// printf("&a[0]=%u\n", &a[0]);
	// printf("&a=%u\n", &a);

	// printf("\na+1=%u\n", a+1);
	// printf("a[0]+1=%u\n", a[0]+1);
	// printf("&a[0][0]+1=%u\n", &a[0][0]+1);
	// printf("&a[0]+1=%u\n", &a[0]+1);
	// printf("&a+1=%u\n", &a+1);
}

int main()
{
	// try1();
	// printf("\n");
	ptp();
	return 0;
}

/**
*	a // addr of a row in 2D array (ptr to array)
*	a[0] // same as array name of 1D array (ptr to int)
*	&a[0][0] // addr of an element in 2D array (ptr to int)
*	&a[0] // addr of a row in 2D array (ptr to array)
*	&a // addr of a 2D array (ptr to 2D array)
*
*	 
*/