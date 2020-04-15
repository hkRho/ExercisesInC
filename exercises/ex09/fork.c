/* Example code for Exercises in C.

Copyright 2016 Allen B. Downey
License: MIT License https://opensource.org/licenses/MIT

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/time.h>
#include <sys/types.h>
#include <wait.h>


// errno is an external global variable that contains
// error information
extern int errno;

// initialize global and heap variable
int global_var = 1;
int *heap_ptr = NULL;

// get_seconds returns the number of seconds since the
// beginning of the day, with microsecond precision
double get_seconds() {
    struct timeval tv[1];

    gettimeofday(tv, NULL);
    return tv->tv_sec + tv->tv_usec / 1e6;
}


void child_code(int i)
{
    sleep(i);
    printf("Hello from child %d.\n", i);
    printf("Child access to GLOBAL: %i, Address: %u\n", global_var, &global_var);
    printf("Child access to HEAP: %i, Address: %u\n", *heap_ptr, heap_ptr);
    printf("Child access to STACK: %i, Address: %u\n", i, &i);
}

// main takes two parameters: argc is the number of command-line
// arguments; argv is an array of strings containing the command
// line arguments
int main(int argc, char *argv[])
{
    int status;
    pid_t pid;
    double start, stop;
    int i, num_children;

    // put a value in the heap_ptr (this must be done within main when the variable is defined globally)
    heap_ptr = (int *) malloc(sizeof(int));
    *heap_ptr = 2;

    // the first command-line argument is the name of the executable.
    // if there is a second, it is the number of children to create.
    if (argc == 2) {
        num_children = atoi(argv[1]);
    } else {
        num_children = 1;
    }

    // create local variable to check shared STACK
    int stack = 1;

    // get the start time
    start = get_seconds();

    for (i=0; i<num_children; i++) {

        // create a child process
        printf("Creating child %d.\n", i);
        pid = fork();

        /* check for an error */
        if (pid == -1) {
            fprintf(stderr, "fork failed: %s\n", strerror(errno));
            perror(argv[0]);
            exit(1);
        }

        /* see if we're the parent or the child */
        if (pid == 0) {
            child_code(i);
            exit(i);
        }
    }

    /* parent continues */
    printf("Hello from the parent.\n");
    printf("Parent access to GLOBAL: %i, Address: %u\n", global_var, &global_var);
    printf("Parent access to HEAP: %i, Address: %u\n", *heap_ptr, heap_ptr);
    printf("Parent access to STACK: %i, Address: %u\n", i, &i);

    for (i=0; i<num_children; i++) {
        pid = wait(&status);

        if (pid == -1) {
            fprintf(stderr, "wait failed: %s\n", strerror(errno));
            perror(argv[0]);
            exit(1);
        }

        // check the exit status of the child
        status = WEXITSTATUS(status);
        printf("Child %d exited with error code %d.\n", pid, status);
    }
    // compute the elapsed time
    stop = get_seconds();
    printf("Elapsed time = %f seconds.\n", stop - start);

    exit(0);
}

/*
For the variables that belong in the global and heap segments of the memory, 
we can see that both the parent and the child process can access those same variables.

### OUTPUT ###
Parent access to GLOBAL: 1, Address: 6299808
Parent access to HEAP: 2, Address: 11460624
Child access to GLOBAL: 1, Address: 6299808
Child access to HEAP: 2, Address: 11460624
### ###### ###

The value of the variables are the same and the address of them is the same for
both the parent and the child.

For the local variable belonging in the stack, we also can see that both the parent
and the child process can access those same variables.

### OUTPUT ###
Parent access to STACK: 1, Address: 3442922008
Child access to STACK: 0, Address: 3442921964
### ###### ###

The parent process has 1 bigger value because the local variable gets incremented
once more before exiting the for loop, and the child process captures the local
variable before it gets incremented.

*/