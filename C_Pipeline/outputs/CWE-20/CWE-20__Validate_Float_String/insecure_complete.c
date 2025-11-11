#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdint.h>
#include <math.h>
#include <limits.h>
#include <stdbool.h>

int is_valid_float(const char* s) {
    char* endptr;
    if (!s) return 0;
    strtod(s, &endptr);
    if (endptr == s) return 0;
    return 1;
}
// Auto-generated test driver
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[])
{
    // Basic argument validation
    if (argc < 2) {
        printf("Usage: %s arg1\n", argv[0]);
        return 1;
    }

    // Parse arguments from command line
    const char* s = argv[1];


    // Execute function
// Call the target function
    int result = is_valid_float(s);

    printf("%ld\n", (long)result);

    return 0;
}