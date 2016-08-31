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