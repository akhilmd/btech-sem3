#include <stdio.h>

#define NUM 6
#define BIGNUM 203041
#define LEN 10

int main();
int fact(int);
int sumArray(int*, int);
int largest(int *, int);
int largest2(int *, int, int);
int sumOfDigits(int);

int main()
{
	printf("factorial of %d = %d\n", NUM, fact(NUM));

	int numbers[LEN] = {91,3,1,4,6,2,9,0,8,7};

	printf("sum of array = %d\n", sumArray(numbers,LEN));
	printf("largest in array = %d\n", largest(numbers,LEN));
	printf("largest in array = %d\n", largest2(numbers,0,LEN-1));
	printf("sum of digits of %d = %d\n", BIGNUM, sumOfDigits(BIGNUM));

	return 0;
}

int fact(int n)
{
	if (n==0)
		return 1;
	return n*fact(n-1);
}

int sumArray(int *ar, int len)
{
	if (len==1)
		return ar[0];
	
	return ar[len-1] + sumArray(ar, len-1);
}

int largest(int *ar, int len)
{
	if (len==1)
		return ar[0];

	int tmp = largest(ar,len-1);

	return ar[len-1] > tmp ? ar[len-1] : tmp;
}

int largest2(int *ar, int beg, int end)
{
	if (beg==end)
		return ar[beg];

	int mid = (beg + end) / 2;
	int ll = largest2(ar,beg,mid);
	int rl = largest2(ar,mid+1,end);
	return ll > rl ? ll : rl;
}

int sumOfDigits(int n)
{
	if (n==0)
		return 0;
	return (n % 10) + sumOfDigits(n / 10);
}