#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdint.h>
#include <math.h>
#include <limits.h>
#include <stdbool.h>

int is_binary_string(const char* s) {
    if (s == NULL) return 0;
    if (*s == '\0') return 0;
    while (*s != '\0') {
        if (*s != '0' && *s != '1') return 0;
        s++;
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
    int result = is_binary_string(s);

    printf("%ld\n", (long)result);

    return 0;
}