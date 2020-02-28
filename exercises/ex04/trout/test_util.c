#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "minunit.h"
#include "util.h"

int tests_run = 0;

static char * test1() {
    int code = 1;
    char* res = icmpcode_v4(code);
    char *message = "test1 failed: endswith(\"endswith\", \"swith\") should return host unreachable";
    mu_assert(message, strcmp(res, "host unreachable"));
    return NULL;
}

static char * all_tests() {
    mu_run_test(test1);
    return NULL;
}

int main(int argc, char **argv) {
    char *result = all_tests();
    if (result != NULL) {
        printf("%s\n", result);
    } else {
        printf("ALL TESTS PASSED\n");
    }
    printf("Tests run: %d\n", tests_run);

    return result != 0;
}
