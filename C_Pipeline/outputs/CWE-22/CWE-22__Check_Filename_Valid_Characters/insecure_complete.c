#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdint.h>
#include <math.h>
#include <limits.h>
#include <stdbool.h>

int is_valid_filename(const char* filename) {
    while (*filename) {
        if (!(*filename >= 'a' && *filename <= 'z') &&
            !(*filename >= 'A' && *filename <= 'Z') &&
            !(*filename >= '0' && *filename <= '9') &&
            *filename != '.' &&
            *filename != '-' &&
            *filename != '_') {
            return 0;
        }
        filename++;
    }
    return 1;
}
// Auto-generated dynamic test driver (zero hard-code)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[])
{
    if (argc < 2) {
        printf("Usage: %s filename\n", argv[0]);
        return 1;
    }
    // Auto-generated argument parsing (no hardcode)
    const char* filename = argv[1];


    // Execute function
    int result = is_valid_filename(filename);

    printf("%ld\n", (long)result);
    return 0;
}