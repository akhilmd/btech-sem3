#include <stdio.h>

#include "../include/FunctionPointers.h"

void __arrfptr()
{
    printf("__arrfptr:\n");

    // f is a 1D array.
    // each element of f is a pointer to a function that
    //     takes 2 int arguments and returns an int
    int (*f[3])(int, int) =
    {   NULL,NULL,NULL
        };
    int res = 0, x = 10, y = 20;

    f[0] = __arrfptr_max;
    f[1] = __arrfptr_min;
    f[2] = __arrfptr_sum;

    res = f[0](x, y);
    printf("max = %d\n", res);

    res = f[1](x, y);
    printf("min = %d\n", res);

    res = f[2](x, y);
    printf("sum = %d\n", res);
}

int __arrfptr_max(int a, int b)
{
    return a > b ? a : b;
}

int __arrfptr_min(int a, int b)
{
    return a < b ? a : b;
}

int __arrfptr_sum(int a, int b)
{
    return (a + b);
}

void __bub_callback()
{
    printf("__bub_callback:\n");

    int i = 0;
    int a[5] =
        { 3, 2, 1, 5, 4 };
    int n = 5;

    printf("Before sort : ");
    for (i = 0; i < n; ++i)
        printf("%d ", a[i]);
    printf("\n");

    __bub_callback_bubsort(a, n, __bub_callback_ascend);

    printf("After sort  : ");
    for (i = 0; i < n; ++i)
        printf("%d ", a[i]);
    printf("\n");
}

void __bub_callback_bubsort(int* ar, int len, int (*compare)(int, int))
{
    int i = 0, j = 0, tmp = 0;

    for (i = len - 1; i >= 0; --i)
        for (j = 0; j < i; ++j)
            if (compare(ar[j], ar[j + 1]))
            {
                tmp = ar[j];
                ar[j] = ar[j + 1];
                ar[j + 1] = tmp;
            }
}

int __bub_callback_ascend(int a, int b)
{
    return a > b ? 1 : 0;
}

int __bub_callback_descend(int a, int b)
{
    return a < b ? 1 : 0;
}

void __fptr()
{
    printf("__fptr:\n");

    int x = 30, y = 10, result = 0;

    // A pointer to a function that takes 2 ints as arguments
    // and returns an int
    int (*f)(int, int) = NULL;

    // address of __fptr_maximum is copied to f
    f = __fptr_maximum;

    result = (*f)(x, y);

    printf("the result = %d\n", result);

    result = f(x, y);

    printf("the result = %d\n", result);
}

int __fptr_maximum(int a, int b)
{
    return a > b ? a : b;
}

void __fptr1()
{
    printf("__fptr1:\n");

    int x = 10, y = 30;

    printf("x = %d and y = %d\n", x, y);

    int max = __fptr1_result(__fptr1_maximum, x, y);
    int min = __fptr1_result(__fptr1_minimum, x, y);

    printf("min = %d\n", min);
    printf("max = %d\n", max);
}

int __fptr1_maximum(int a, int b)
{
    return a > b ? a : b;
}

int __fptr1_minimum(int a, int b)
{
    return a < b ? a : b;
}

int __fptr1_result(int (*func)(int, int), int a, int b)
{
    return (*func)(a, b);
}

void test_fp()
{
    __arrfptr();
    __bub_callback();
    __fptr();
    __fptr1();
}
