#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdint.h>
#include <math.h>
#include <limits.h>
#include <stdbool.h>

int contains_data_protocol(const char* input) {
    if (!input) return 0;
    const char* ptr = input;
    while (*ptr) {
        if ((*ptr == 'd' || *ptr == 'D') &&
            (*(ptr + 1) == 'a' || *(ptr + 1) == 'A') &&
            (*(ptr + 2) == 't' || *(ptr + 2) == 'T') &&
            (*(ptr + 3) == 'a' || *(ptr + 3) == 'A') &&
            (*(ptr + 4) == ':')) {
            return 1;
        }
        ptr++;
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
        printf("Usage: %s input\n", argv[0]);
        return 1;
    }
    // Auto-generated argument parsing (no hardcode)
    const char* input = argv[1];


    // Execute function
    int result = contains_data_protocol(input);

    printf("%ld\n", (long)result);
    return 0;
}