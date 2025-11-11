#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdint.h>
#include <math.h>
#include <limits.h>
#include <stdbool.h>

int has_dot_prefix(const char* path) {
    if (!path) return 0;
    
    char* token = strtok(path, "/");
    while (token != NULL) {
        if (token[0] == '.') return 1;
        token = strtok(NULL, "/");
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
    int result = has_dot_prefix(path);

    printf("%ld\n", (long)result);
    return 0;
}