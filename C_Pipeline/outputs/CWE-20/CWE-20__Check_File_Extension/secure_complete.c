#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdint.h>
#include <math.h>
#include <limits.h>
#include <stdbool.h>

int has_extension(const char* filename, const char* ext) {
    unsigned long fl = 0;
    unsigned long el = 0;
    unsigned long i;
    const char* p;

    if (filename == 0 || ext == 0) return 0;

    while (filename[fl] != '\0') fl++;
    while (ext[el] != '\0') el++;

    if (el == 0) return 0;
    if (el > fl) return 0;

    p = filename + (fl - el);

    for (i = 0; i < el; i++) {
        if (p[i] != ext[i]) return 0;
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