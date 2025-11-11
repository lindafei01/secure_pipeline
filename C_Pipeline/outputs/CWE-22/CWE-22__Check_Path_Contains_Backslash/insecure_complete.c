#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdint.h>
#include <math.h>
#include <limits.h>
#include <stdbool.h>

int path_contains_backslash(const char* path) {
    char special_path[256];
    if (path == NULL) return 0;
    strcpy(special_path, path);
    for (int i = 0; special_path[i] != '\0'; i++) {
        if (special_path[i] == '\\') return 1;
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
    int result = path_contains_backslash(path);

    printf("%ld\n", (long)result);
    return 0;
}