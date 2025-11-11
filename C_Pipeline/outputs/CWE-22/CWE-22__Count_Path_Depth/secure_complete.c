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
    if (!path || path[0] == '\0') {
        return -1;
    }
    int i = 0;
    while (path[i] != '\0') {
        if (path[i] == '/') {
            i++;
            continue;
        }
        if (path[i] == '.' && path[i+1] == '.') {
            if ((i > 0 && path[i-1] != '/') || (path[i+2] != '\0' && path[i+2] != '/')) {
                return -1;
            }
            depth--;
            if (depth < 0) {
                return -1;
            }
            i += 2;
        } else {
            while (path[i] != '/' && path[i] != '\0') {
                i++;
            }
            depth++;
        }
    }
    return depth;
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