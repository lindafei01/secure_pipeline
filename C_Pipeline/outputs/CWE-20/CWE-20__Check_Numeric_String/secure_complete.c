#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdint.h>
#include <math.h>
#include <limits.h>
#include <stdbool.h>

int is_numeric(const char* s) {
    if (s == NULL) return 0;
    const unsigned char* p = (const unsigned char*)s;
    if (*p == '\0') return 0;
    while (*p) {
        if (*p < '0' || *p > '9') return 0;
        p++;
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
    if (argc < 2) {
        printf("Usage: %s arg1\n", argv[0]);
        return 1;
    }

    // Parse arguments from command line
    const char* s = argv[1];


    // Execute function
// Call the target function
    int result = is_numeric(s);

    printf("%ld\n", (long)result);

    return 0;
}