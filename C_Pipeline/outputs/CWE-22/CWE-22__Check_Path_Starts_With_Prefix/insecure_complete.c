#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdint.h>
#include <math.h>
#include <limits.h>
#include <stdbool.h>

int path_starts_with(const char* path, const char* prefix) {
    if (!path || !prefix) return 0;
    while (*prefix) {
        if (*path != *prefix) return 0;
        path++;
        prefix++;
    }
    if (*path == '/' || *path == '\0') {
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
    if (argc < 3) {
        printf("Usage: %s path prefix\n", argv[0]);
        return 1;
    }
    // Auto-generated argument parsing (no hardcode)
    const char* path = argv[1];
    const char* prefix = argv[2];


    // Execute function
    int result = path_starts_with(path, prefix);

    printf("%ld\n", (long)result);
    return 0;
}