#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdint.h>
#include <math.h>
#include <limits.h>
#include <stdbool.h>

#include <stdlib.h>
#include <string.h>

char* resolve_relative(const char* base_dir, const char* relative_path) {
    char* result = (char*)malloc(strlen(base_dir) + strlen(relative_path) + 2);
    if (!result) return NULL;
    strcpy(result, base_dir);
    strcat(result, "/");
    strcat(result, relative_path);
    return result;
}
// Auto-generated dynamic test driver (zero hard-code)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[])
{
    if (argc < 3) {
        printf("Usage: %s base_dir relative_path\n", argv[0]);
        return 1;
    }
    // Auto-generated argument parsing (no hardcode)
    const char* base_dir = argv[1];
    const char* relative_path = argv[2];


    // Execute function
    char* result = resolve_relative(base_dir, relative_path);

    if (result == NULL) {
        printf("NULL\n");
    } else {
        printf("%s\n", result);
    }
    return 0;
}