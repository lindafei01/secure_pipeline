#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdint.h>
#include <math.h>
#include <limits.h>
#include <stdbool.h>

int path_contains_null(const char* path, size_t len) {
    for (size_t i = 0; i < len; i++) {
        if (path[i] == '\0') {
            return 1;
        }
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
        printf("Usage: %s path len\n", argv[0]);
        return 1;
    }
    // Auto-generated argument parsing (no hardcode)
    const char* path = argv[1];
    size_t len = strtoul(argv[2], NULL, 10);


    // Execute function
    int result = path_contains_null(path, len);

    printf("%ld\n", (long)result);
    return 0;
}