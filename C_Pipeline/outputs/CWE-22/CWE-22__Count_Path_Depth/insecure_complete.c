#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdint.h>
#include <math.h>
#include <limits.h>
#include <stdbool.h>

int count_path_depth(const char* path) {
    int depth = 0;
    const char *p = path;
    char current_dir[1024];
    while (*p != '\0') {
        if (*p == '/' || *p == '\\') {
            depth++;
        } else if (*p == '.' && (*(p + 1) == '/' || *(p + 1) == '\\' || *(p + 1) == '\0')) {
            // stay at the same level
        } else if (*p == '.' && *(p + 1) == '.' && (*(p + 2) == '/' || *(p + 2) == '\\' || *(p + 2) == '\0')) {
            depth--;
            p++;
        } else {
            current_dir[depth] = *p;
        }
        p++;
    }
    return depth < 0 ? -1 : depth;
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
    int result = count_path_depth(path);

    printf("%ld\n", (long)result);
    return 0;
}