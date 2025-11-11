#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdint.h>
#include <math.h>
#include <limits.h>
#include <stdbool.h>

int ends_with_separator(const char* path) {
    if (path == NULL || *path == '\0') {
        return 0;
    }
    int length = 0;
    while (path[length] != '\0') {
        length++;
    }
    if (length > 0 && (path[length - 1] == '/' || path[length - 1] == '\\')) {
        return 1;
    }
    return 0;
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
    int result = ends_with_separator(path);

    printf("%ld\n", (long)result);
    return 0;
}