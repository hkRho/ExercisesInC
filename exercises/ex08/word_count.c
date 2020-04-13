#include <stdio.h>
#include <stdlib.h>
#include <glib.h>

void main() {
    GHashTable *hash_table = g_hash_table_new(g_str_hash, g_str_equal);
    GScanner *g_scanner = g_scanner_new(NULL);

    // set file pointer to input file
    FILE *fptr;
    fptr = fopen("simple_text.txt", "r");

    // exit if file cannot be accessed
    if (fptr == NULL) {
        printf("Something's wrong!");
        exit(1);
    }

    // give file to lexical analyzer
    g_scanner_input_file(g_scanner, fptr);

    while (!g_scanner_eof(g_scanner)) {
        g_scanner_get_next_token(g_scanner);
        gconstpointer *key = (gconstpointer *) g_scanner->value.v_string;
        gint *val = (gint *) g_hash_table_lookup(hash_table, key);

        if (key == NULL) {
            g_hash_table_insert(hash_table, key, 1);
        }
        else {
            g_hash_table_insert(hash_table, key, val+1);
        }
    }
}
