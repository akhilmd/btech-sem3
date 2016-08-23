long fact(long n)
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