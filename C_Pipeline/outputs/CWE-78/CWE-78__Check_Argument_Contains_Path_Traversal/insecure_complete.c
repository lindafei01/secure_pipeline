#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdint.h>
#include <math.h>
#include <limits.h>
#include <stdbool.h>

int has_path_traversal(const char* argument) {
    if (!argument) return 0;
    return strstr(argument, "..") != NULL || argument[0] == '/';
}
// Auto-generated dynamic test driver (zero hard-code)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[])
{
    if (argc < 2) {
        printf("Usage: %s argument\n", argv[0]);
        return 1;
    }
    // Auto-generated argument parsing (no hardcode)
    const char* argument = argv[1];


    // Execute function
    int result = has_path_traversal(argument);

    printf("%ld\n", (long)result);
    return 0;
}