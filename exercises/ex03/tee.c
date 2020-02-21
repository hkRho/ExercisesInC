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
                append_flag = 1;
                break;
            case 'i':
                // OPTIONAL
                // break;
            default:
                fprintf(stderr, "Unknown option: '%s'\n", optarg);
                return 1;
         }
     }

     argc -= optind;
     argv += optind;

     // loop for writing output to all the files specified
     for (i=0; i<argc; i++) {
         if (append_flag) {
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
         }
         // if append_flag == 0 just write to file
         else {
             FILE* out_file = fopen(path, "w");
             printf("file not found\n");
         }
     }
 }

 /*
 3. For writing our own tee command, the part that slowed me down the most was
    figuring out how tee is called upon and thinking about the piping part. The
    part that worked though was the implementation of the structure from Head
    First C to solve this exercise. Next time, it would be better to begin
    programming after having a clear understanding of how the structure of
    the part will interact with each other and what the input/output/call to
    the program would be.

4. For the professional implementation, one of the things that I found different
   from my implementation were the use of oflags such as O_WRONLY or O_CREAT.
 */
