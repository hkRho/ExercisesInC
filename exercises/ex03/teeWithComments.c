#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>


int main(int argc, char* argv[]) {
    char ch;
    char path[300] = "/home/hk/SoftSys/ExercisesInC/exercises/ex03/";
    int append_flag;
    int i = 1;

    while ((ch = getopt(argc, argv, "ai")) != EOF) {
        switch(ch) {
           case 'a':
               // append_flag = 1;

               strcat(path, argv[i+1]);
               printf("Path: %s\n", path);

               // file exists, so append to file
               if (access(argv[i+1], F_OK) == 0) {
                   FILE* out_file = fopen(path, "a");
                   printf("file found\n");
               }
               // file doesn't exist, so write to file
               else {
                   FILE* out_file = fopen(path, "w");
                   printf("file not found\n");
               }
               break;
           case 'i':
               // break;
               // OPTIONAL
           default:
               fprintf(stderr, "Unknown option: '%s'\n", optarg);
               return 1;
        }
    }
    // printf("%i\n",optind);
    // printf("%i\n",argc);
    argc -= optind;
    argv += optind;
}
