#include <stdio.h>

int main() {
    int x = 5;
    int y = x + 1;
    // printf("%s\n", "Hello World!");
    printf("%d", y);
    return 0;
}

/*
1. It seems like "movl	$5, -4(%rbp)" this line stores only the value of the
   variable x.

2. When the -O2 flag was added, the assembly language output became longer in
   total, but the main section became shorter.

3. Without optimization: The main section is longer than with optimization.
                         It has fewer tags above "main:" that start with ".L".
   With optimization: The main section is shorter than without optimization.
                      It has more tags above "main:" that start with ".L".

4. Without optimization: I can only find the x value in the main section.
   With optimization: I can only find the y value in the main section.
   Since x is not referred after the line "int y = x + 1;", it is efficient
   to not store x in the optimized version. It seems like optimization works
   its best to make the main section as concise as possible.

5. To go through the Optimization section, I compared the optimized and
   non-optimized versions of the assembly code by first taking pictures but
   then later saving them as different files. By going over this section, I was
   able to discover that the assembly language output with the optimization
   always had a shorter main section.
*/
