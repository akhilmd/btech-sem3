#include <stdio.h>

int main()
{
	int n=10;
	int *p = &n;
	int **p2p = &p;

	printf("n=%d\n",n);
	printf("n=%d\n",*p);
	printf("n=%d\n",**p2p);

	return 0;
}