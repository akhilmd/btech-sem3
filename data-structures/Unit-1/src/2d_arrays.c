#include <stdio.h>
#include <stdlib.h>

#include "../include/2DArrays.h"

// Create a 2D array dynamically
void __dtarray()
{
    printf("__dtarray\n");
    int i = 0, j = 0;
    int r = 5, c = 5;
    int** p;

    //create rows
    p = (int**) malloc(r * sizeof(int*));

    //create cols
    for (i = 0; i < r; ++i)
        p[i] = (int*) malloc(c * sizeof(int));

    for (i = 0; i < r; ++i)
        for (j = 0; j < c; ++j)
            p[i][j] = i + j;

    printf("Printing the array elements:\n");
    for (i = 0; i < r; ++i)
    {
        for (j = 0; j < c; ++j)
            printf("%d ", p[i][j]);
        printf("\n");
    }
}

// Prints the address of every row
void __tdarray1()
{
    printf("__tdarray1:\n");
    int i = 0;
    int s[5][2] =
        {
            { 1234, 56 },
            { 1212, 33 },
            { 1434, 80 },
            { 1312, 78 },
            { 1203, 75 } };

    printf("Printing the addresses:\n");
    for (i = 0; i <= 4; ++i)
        printf("Address of %d th 1-D array = %p\n", i, s[i]);
}

// Create a statically allocated 2D Array
void __tdarray2()
{
    printf("__tdarray2:\n");
    int i = 0, j = 0;
    int s[5][2] =
        {
            { 1234, 56 },
            { 1212, 33 },
            { 1434, 80 },
            { 1312, 78 },
            { 1203, 75 } };

    printf("Printing the values:\n");
    for (i = 0; i <= 4; ++i)
    {
        for (j = 0; j < 2; ++j)
            printf("%d ", s[i][j]);
        printf("\n");
    }
}

// Accessing the array elements with *
void __tdarray3()
{
    printf("__tdarray3:\n");
    int i, j;
    int s[5][2] =
        {
            { 1234, 56 },
            { 1212, 33 },
            { 1434, 80 },
            { 1312, 78 },
            { 1203, 75 } };

    printf("Printing the values:\n");
    for (i = 0; i <= 4; ++i)
    {
        for (j = 0; j < 2; ++j)
            printf("%d ", *(*(s + i) + j)); //same as s[i][j]

        printf("\n");
    }
}

// Making pointers to a 2D Array
void __tdarray4()
{
    printf("__tdarray4:\n");
    int i = 0, j = 0;
    int s[3][4] =
        { 5, 7, 5, 9, 4, 6, 3, 1, 2, 9, 0, 6 };

    // Pointer to an array containing 4 ints
    int (*q)[4];

    q = s;

    for (i = 0; i < 3; ++i)
    {
        printf("address of %d th 1D array= %p\n", i, q);
        // Increment by 4*4bytes
        q++;
    }
}

void __tdarray5()
{
    printf("__tdarray5:\n");
    int s[3][4] =
        { 5, 7, 5, 9, 4, 6, 3, 1, 2, 9, 0, 6 };

    // passing a 2D array
    __tdarray5_display(s, 3, 4);
}

// q is a pointer to an array of size [4], which is the
// first element of the 2D array of size [][4]
void __tdarray5_display(int (*q)[4], int row, int col)
{
    int i = 0, j = 0;
    for (i = 0; i < row; ++i)
    {
        for (j = 0; j < col; ++j)
            printf("%d ", q[i][j]);
        printf("\n");
    }
}

void __tdarray6()
{
    printf("__tdarray6:\n");
    int s[3][4] =
        { 5, 7, 5, 9, 4, 6, 3, 1, 2, 9, 0, 6 };

    // s[0] is the first element in 2D array
    // s[0] is a 1D array
    // &s[0] is the address of the 1D array
    __tdarray6_display(&s[0], 3, 4);
}

void __tdarray6_display(int (*q)[4], int row, int col)
{
    int i = 0, j = 0;
    int* p = NULL;

    for (i = 0; i < row; ++i)
    {
        // q + i gives corresponding 1D array(row) of the 2D array.
        // by explicitly casting to int*, we can get each element
        // of the 1D array.
        p = (int*) (q + i);
        // p = *(q+i) is also valid
        // since q is an array of arrays, *(q + i) will give the ith array.
        // hence, *q will result in an integer pointer
        for (j = 0; j < col; ++j)
            printf("%d ", *(p + j));
        printf("\n");
    }
}

void __tdarray12()
{
    printf("__tdarray12:\n");
    printf("All addresses are in hexadecimal.\n");

    int ar2d[3][3] =
        { 1, 2, 3, 4, 5, 6, 7, 8, 9 };

    // ar2d is a 2D Array.
    // ar2d is a pointer to first element of a 2D Array:
    //     first element of a 2D Array is a 1D Array.
    // ar2d is a pointer to a 1D Array.
    printf("%13s = %p\n", "ar2d", ar2d);
    // Incrementing ar2d will take it ahead by the sizeof of the 1D Array it points to
    printf("%13s = %p\n", "ar2d+1", ar2d + 1);

    // ar2d is a 2D Array.
    // ar2d[0] is the first element of a 2D Array:
    //     first element of a 2D Array is a 1D Array.
    // ar2d[0] is a pointer to first element of a 1D Array.
    //     first element of the 1D Array is an int
    // ar2d[0] is a pointer to an int
    printf("%13s = %p\n", "ar2d[0]", ar2d[0]);
    // Incrementing ar2d[0] will take it ahead by size of an int
    printf("%13s = %p\n", "ar2d[0]+1", ar2d[0] + 1);

    // ar2d[0][0] is first element of first element of a 2D array.
    // ar2d[0][0] is an int.
    // &ar2d[0][0] is a pointer to an int
    printf("%13s = %p\n", "&ar2d[0][0]", &ar2d[0][0]);
    // Incrementing &ar2d[0][0] will take it ahead by size of an int
    printf("%13s = %p\n", "&ar2d[0][0]+1", &ar2d[0][0] + 1);

    // ar2d[0] is first element of 2D array.
    //     first element of a 2D Array is a 1D Array.
    // &ar2d[0] is pointer to a 1D Array.
    printf("%13s = %p\n", "&ar2d[0]", &ar2d[0]);
    // Incrementing &ar2d[0] will take it ahead by the sizeof of the 1D Array it points to
    printf("%13s = %p\n", "&ar2d[0]+1", &ar2d[0] + 1);

    // ar2d is a 2D Array.
    // &ar2d is a pointer to a 2D Array
    printf("%13s = %p\n", "&ar2d", &ar2d);
    // Incrementing ar2d will take it ahead by the size of the 2D Array.
    printf("%13s = %p\n", "&ar2d+1", &ar2d + 1);
}

void test_2da()
{
    __dtarray();
    __tdarray1();
    __tdarray2();
    __tdarray3();
    __tdarray4();
    __tdarray5();
    __tdarray6();
    __tdarray12();
}
