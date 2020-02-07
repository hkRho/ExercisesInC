/* Example code for Think OS.

Copyright 2014 Allen Downey
License: GNU GPLv3

*/

#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

int *foo() {
    int i;
    int array[SIZE];

    // printf("%p\n", array);

    for (i=0; i<SIZE; i++) {
        array[i] = 42;
    }
    return array;
}

void bar() {
    int i;
    int array[SIZE];

    // printf("%p\n", array);

    for (i=0; i<SIZE; i++) {
        array[i] = i;
    }
}

int main()
{
    int i;
    int *array = foo();
    bar();

    for (i=0; i<SIZE; i++) {
        printf("%d\n", array[i]);
    }

    return 0;
}

/*
1. This file is seems to make an array of size 5 and put values of 42 into each
    bytes of the array. This part seems to be done by the function foo() and
    printing the array is done by the main().

2. The file returns a warning that says 'function returns addres of local variable'.
    I think it means that the function foo() is returning an invalid memory location
    since variables in the stack are destroyed when the function terminates.

3. I get a segmentation fault error. I am not completely sure what happened,
    but it seems that the array pointer does not know where to point to when
    assigned to foo(). When all the code within foo() is executed, all the
    variables including array are dumped so the *array in main() seems to get
    dereferenced.
    ???
4. From commenting out the print statements, I only get the segmentation error,
    but with the print statements, the address of the array in foo() and bar()
    are the same.

5. When returning the array pointer to a stack allocated data, it seems like
    the address for the data stays the same regardless of a function's termination
    and another function calling on a variable with the same name.
    ???
*/
