#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdint.h>
#include <math.h>
#include <limits.h>
#include <stdbool.h>

int has_extension(const char* filename, const char* ext) {
    if (!filename || !ext) return 0;
    size_t fl = strlen(filename);
    size_t el = strlen(ext);
    const char* pos = filename + (fl - el);
    for (size_t i = 0; i < el; i++) {
        if (pos[i] != ext[i]) return 0;
    }
    return 1;
}
// Auto-generated test driver
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[])
{
    // Basic argument validation
    if (argc < 3) {
        printf("Usage: %s arg1 arg2\n", argv[0]);
        return 1;
    }

    // Parse arguments from command line
    const char* filename = argv[1];
    const char* ext = argv[2];


    // Execute function
// Call the target function
    int result = has_extension(filename, ext);

    printf("%ld\n", (long)result);

    return 0;
}