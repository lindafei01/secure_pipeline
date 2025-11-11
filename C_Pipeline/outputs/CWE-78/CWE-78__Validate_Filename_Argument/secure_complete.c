#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdint.h>
#include <math.h>
#include <limits.h>
#include <stdbool.h>

int is_valid_filename_arg(const char* filename) {
    if (filename == NULL) {
        return 0;
    }
    while (*filename) {
        char c = *filename;
        if (!(('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z') || ('0' <= c && c <= '9') ||
              c == '.' || c == '-' || c == '_')) {
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
    int result = is_valid_filename_arg(filename);

    printf("%ld\n", (long)result);
    return 0;
}