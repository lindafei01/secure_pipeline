#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdint.h>
#include <math.h>
#include <limits.h>
#include <stdbool.h>

int path_escapes_jail(const char* path, int max_depth) {
    int depth = 0;
    const char* ptr = path;
    
    if (ptr == NULL) return 0;

    while (*ptr != '\0') {
        if (*ptr == '/' || *ptr == '\\') {
            ++ptr;
            continue;
        }
        
        if (*ptr == '.' && *(ptr + 1) == '.' && (*(ptr + 2) == '/' || *(ptr + 2) == '\\' || *(ptr + 2) == '\0')) {
            --depth;
            ptr += 2;
        } else {
            ++depth;
            while (*ptr != '/' && *ptr != '\\' && *ptr != '\0') {
                ++ptr;
            }
        }

        if (depth < -max_depth) return 1;
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