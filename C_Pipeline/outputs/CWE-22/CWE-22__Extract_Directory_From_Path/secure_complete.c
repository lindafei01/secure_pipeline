#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdint.h>
#include <math.h>
#include <limits.h>
#include <stdbool.h>

char* extract_directory(const char* path) {
    if (!path) return NULL;
    size_t len = 0;
    while (path[len] != '\0') len++;
    if (len == 0) return NULL;
    size_t last_sep = len;
    while (last_sep > 0 && path[last_sep - 1] != '/') last_sep--;
    if (last_sep == 0) return NULL;
    char *result = (char*)malloc(last_sep + 1);
    if (!result) return NULL;
    for (size_t i = 0; i < last_sep; i++) {
        result[i] = path[i];
    }
    result[last_sep] = '\0';
    return result;
}
// Auto-generated dynamic test driver (zero hard-code)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[])
{
    if (argc < 2) {
        printf("Usage: %s path\n", argv[0]);
        return 1;
    }
    // Auto-generated argument parsing (no hardcode)
    const char* path = argv[1];


    // Execute function
    char* result = extract_directory(path);

    if (result == NULL) {
        printf("NULL\n");
    } else {
        printf("%s\n", result);
    }
    return 0;
}