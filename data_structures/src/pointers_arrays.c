#include <stdio.h>
#include <stdlib.h>

//program to manipulate array elements through pointers
void __array2()
{
    printf("__array2:\n");

    int a[] =
    { 2, 4, 6, 8, 10 };

    int i = 0;

    for (i = 0; i <= 4; ++i)
    {
        *(a + i) = a[i] + i[a]; //every element of the array doubles
        printf("%d ", *(i + a));
    }

    printf("\n");
}

void __f(int x, int* y)
{
    x = *y += 2;
}

void __array3()
{
    printf("__array3:\n");

    int a[5] =
    { 2, 4, 6, 8, 10 };

    int i, b = 5;

    for (i = 0; i < 5; i++)
    {
        __f(a[i], &b); //array element passed by value, b by reference
        printf("a[%d]=%d, b=%d\n", i, a[i], b);
    }
}

void __array4()
{
    printf("__array4:\n");

    int arr[] =
    { 0, 1, 2, 3, 4 };

    int* ptr;

    //prints 0,1,2,3,4
    for (ptr = &arr[0]; ptr <= &arr[4]; ptr++)
        printf("%d ", *ptr);

    printf("\n");
}

void __array5()
{
    printf("__array5:\n");

    int arr[] =
    { 0, 1, 2, 3, 4 };

    int* ptr;
    //prints 4,3,2,1,0

    for (ptr = arr + 4; ptr >= arr; ptr--)
        printf("%d ", arr[ptr - arr]);

    printf("\n");
}

void __array6()
{
    printf("__array6:\n");

    int a[] =
    { 0, 1, 2, 3, 4 };

    int* p[] =
    { a, a + 1, a + 2, a + 3, a + 4 };

    int** ptr = p;

    printf("a= %p *a= %d\n", a, *a);
    printf("p= %p *p= %p **p= %d\n", p, *p, **p);
    printf("ptr= %p *ptr= %p **ptr= %d\n", ptr, *ptr, **ptr);
    /*

     1. a=address of first element of a i.e 0
     *a= value of the first element of the array

     2. p = address of first element of array of p
     * p = value of the first element of p 
     **p= 0

     3. ptr : value of ptr i.e p
     *ptr = *p = a
     **ptr = **p = *a = 

     */
}

void __array7()
{
    printf("__array7:\n");

    long a[] =
    { 0, 1, 2, 3, 4 };

    long* p[] =
    { a, a + 1, a + 2, a + 3, a + 4 };

    long** ptr = p;

    ptr++;
    printf("%ld %ld %ld\n", ptr - p, *ptr - a, **ptr);

    /*
     ++ is bound to ptr, but it is postfix operator,
     so ptr is dereferenced and nothing is done.
     Then, ptr is incremented and now points to p+2
     */
    *ptr++;
    printf("%ld %ld %ld\n", ptr - p, *ptr - a, **ptr);

    *++ptr;
    printf("%ld %ld %ld\n", ptr - p, *ptr - a, **ptr);

    ++*ptr;
    printf("%ld %ld %ld\n", ptr - p, *ptr - a, **ptr);
}

void __drray()
{
    printf("__drray:\n");

    int i, n = 10;
    int* p;

    p = (int*) malloc(n * sizeof(int));

    for (i = 0; i < n; i++)
        p[i] = i;

    for (i = 0; i < n; i++)
        printf("%d ", p[i]); //*(p+i);

    printf("\n");
}

void __pointer()
{
    printf("__pointer:\n");

    int x = 10;
    int* y;

    printf("Value of x=%d\n", x); //prints 10
    printf("Address of x = %p\n", &x); //address of x

    y = &x;

    printf("The value of x=%d\n", *y); //print 10(value of x)
    printf("The value of x=%d\n", *(&x)); //10(value of x)
}

void __ptr()
{
    printf("__ptr:\n");

    int x = 10;
    int *y;
    int **z;

    y = &x;
    z = &y;

    printf("The value of x= %d\n", x);
    printf("The address of x=%p\n", &x);
    printf("The value of x=%d\n", *(&x));
    printf("the value of x=%d\n", *y);
    printf("the value of x=%d\n", **z);
}

void __disp1(int* a, int n)
{
    int i;

    for (i = 0; i < n; i++)
    {
        printf("The address of the %d element is %p\n", i, a);
        a++;
    }
}

void __ptr1()
{
    printf("__ptr1:\n");
    
    int a[5] =
    { 1, 2, 3, 4, 5 };
    
    __disp1(a, 5);
}

void __disp2(int* a, int n)
{
    int i;

    for (i = 0; i < n; i++)
        ++*a;

    //the first element gets incremented 5 times
    //prints 6,2,3,4,5

    printf("The values of the array..\n");

    for (i = 0; i < n; i++)
        printf(" %d", a[i]);

}

void __ptr2()
{
    printf("__ptr2:\n");
    
    int a[5] =
    { 1, 2, 3, 4, 5 };
    
    __disp2(&a[0], 5);
    
    printf("\n");
}


void test_pa()
{
    __array2();
    __array3();
    __array4();
    __array5();
    __array6();
    __array7();

    __drray();
    __pointer();
    __ptr();
    __ptr1();
    __ptr2();
}