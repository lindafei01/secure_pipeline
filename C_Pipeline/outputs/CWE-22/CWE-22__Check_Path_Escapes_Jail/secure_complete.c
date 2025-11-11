#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdint.h>
#include <math.h>
#include <limits.h>
#include <stdbool.h>

int path_escapes_jail(const char* path, int max_depth) {
    if (!path) return 0;
    
    int up_count = 0, depth = 0;
    const char *ptr = path;

    while (*ptr != '\0') {
        if (*ptr == '.') {
            if (*(ptr + 1) == '.') {
                if ((ptr == path || *(ptr - 1) == '/') && (*(ptr + 2) == '/' || *(ptr + 2) == '\0')) {
                    up_count++;
                    ptr += 2;
                    continue;
                }
            }
        }

        if (*ptr == '/') {
            depth++;
            while (*ptr == '/') ptr++;
            continue;
        }

        ptr++;
    }

    return (up_count > max_depth) ? 1 : 0;
}
// Auto-generated dynamic test driver (zero hard-code)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[])
{
    if (argc < 3) {
        printf("Usage: %s path max_depth\n", argv[0]);
        return 1;
    }
    // Auto-generated argument parsing (no hardcode)
    const char* path = argv[1];
    int max_depth = atoi(argv[2]);


    // Execute function
    int result = path_escapes_jail(path, max_depth);

    printf("%ld\n", (long)result);
    return 0;
}