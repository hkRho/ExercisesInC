/* Software Systems SP2020
 * Head First C
 * @Author: HK Rho
 */

 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
 #include <ctype.h>

 #define ARR_SIZE 3
 #define BUFFER 3


int get_input(int* exit_signal);
int get_sum(int* input_arr, int length);


int main() {
    int store_input[ARR_SIZE];
    int sum = 0;
    int i = 0;
    int exit_signal = 0; // 1 = don't exit, 0 = exit
    int val = 0;

    while (i < ARR_SIZE) {
        puts("Enter a number but press 'Ctrl D' to finish and find the sum: ");
        val = get_input(&exit_signal);

        // since atoi(alphabet) returns 0, catch when alphabets are entered
        if (val != 0) {
            store_input[i] = val;
        }
        else {
            // if case for when 0 is entered
            if (exit_signal == 1) {
                store_input[i] = val;
            } else {
                puts("You have entered an invalid value.\n");
                break;
            }
        }
        i += 1;
    }
    printf("You have reached the maximum array size.\n");
    sum = get_sum(store_input, i);
    printf("The final sum: %d\n", sum);

    return 0;
}


/*  Gets the user input and then returns the string input as a integer value if
    an integer was entered.

    exit_signal: pointer to a flag that determines whether the program should
                 break out of the while loop in the main function
*/
int get_input(int* exit_signal) {
    char str_input[BUFFER];
    char c;

    // case when user doesn't presses Ctrl-D
    while (fgets(str_input, BUFFER, stdin) != NULL){
        // case when the input exceeds the buffer
        if (strlen(str_input) >= BUFFER || (str_input[strlen(str_input) - 1] != '\n')) {
            printf("Error: you have exceeded the buffer.");
            *exit_signal = 0;
            return 0;
        }
        else if (strlen(str_input) < BUFFER) {
            // checks if input value == 0 and if so, set exit signal to don't exit
            if (*str_input == '0') {
                *exit_signal = 1;
                return atoi(str_input);
            }
            // checks if input value are alphabets
            else if (atoi(str_input) == 0) {
                *exit_signal = 0;
                return atoi(str_input);
            }
            *exit_signal = 1;
            return atoi(str_input);
        }
        // case when user presses Ctrl-D
        else {
            *exit_signal = 0;
            return 0;
        }
    }

    return 0;
}


/*  Gets the sum of all the values that were entered into the array.

    input_arr: pointer to an array where all the values that were entered are stored
    length: integer value to track the length of the array that stores all the values
*/
int get_sum(int* input_arr, int length) {
    int j = 0;
    int temp_sum = 0;

    for (j = 0; j < length; j++) {
        temp_sum += *(input_arr + j);
        printf("Arr val: %d\n",*(input_arr + j));
    }

    return temp_sum;
}
