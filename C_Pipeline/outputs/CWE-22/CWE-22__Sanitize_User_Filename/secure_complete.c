#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdint.h>
#include <math.h>
#include <limits.h>
#include <stdbool.h>

char* sanitize_filename(const char* filename) {
    size_t len = 0;
    while (filename[len] != '\0') {
        len++;
    }
    
    char* safe_filename = (char*)malloc(len + 1);
    if (!safe_filename) {
        return NULL;
    }

    size_t j = 0;
    for (size_t i = 0; i < len; i++) {
        char c = filename[i];
        if ((c >= 32 && c < 127) && c != '/' && c != '\\') {
            if (c == ':' || c == '*' || c == '?' || c == '"' || c == '<' || c == '>' || c == '|') {
                safe_filename[j++] = '_';
            } else {
                safe_filename[j++] = c;
            }
        }
    }
    safe_filename[j] = '\0';

    if (j == 0) {
        free(safe_filename);
        return NULL;
    }

    return safe_filename;
}
// Auto-generated dynamic test driver (zero hard-code)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[])
{
    if (argc < 2) {
        printf("Usage: %s filename\n", argv[0]);
        return 1;
    }
    // Auto-generated argument parsing (no hardcode)
    const char* filename = argv[1];


    // Execute function
    char* result = sanitize_filename(filename);

    if (result == NULL) {
        printf("NULL\n");
    } else {
        printf("%s\n", result);
    }
    return 0;
}