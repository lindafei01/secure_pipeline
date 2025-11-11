#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdint.h>
#include <math.h>
#include <limits.h>
#include <stdbool.h>

int is_absolute_path(const char* path) {
    if (path == NULL) return 0;
    if (path[0] == '/' || (path[1] == ':' && (path[2] == '\\' || path[2] == '/'))) return 1;
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
    int result = is_absolute_path(path);

    printf("%ld\n", (long)result);
    return 0;
}