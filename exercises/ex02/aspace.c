/* Example code for Think OS.

Copyright 2014 Allen Downey
License: GNU GPLv3

*/

#include <stdio.h>
#include <stdlib.h>

void print_address(int var);
int var1;

int main ()
{
    int var2 = 5;
    void *p = malloc(128);
    void *p2 = malloc(128);
    char *s = "Hello, World";

    printf ("Address of main is %p\n", main);
    printf ("Address of var1 is %p\n", &var1);

    // added to compare address output for number 5
    print_address(var2);
    printf ("Address of var2 is %p\n", &var2);

    printf ("p points to %p\n", p);

    // added to see result for number 4
    printf ("p2 points to %p\n", p2);
    printf ("s points to %p\n", s);

    int *num1 = malloc(10);
    int *num2 = malloc(20);
    printf ("num1 points to %p\n", num1);
    printf ("num2 points to %p\n", num2);

    return 0;
}

void print_address(int var) {
    printf ("Address of the local variable is: %p\n", &var);
}

/*
3. Sketch uploaded in same directory.

4. The heap of the system grows - the address of the newly added pointer (p2) is
    greater than the address of p.

5. When the function printed out the address of the local variable, the stack
    grew downward, as its address was lower than the address when it was printed
    from the printf call within the main().

6. There are 32 bytes in between num1 and num2.
*/
