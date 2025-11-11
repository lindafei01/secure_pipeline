#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdint.h>
#include <math.h>
#include <limits.h>
#include <stdbool.h>

int contains_encoded_characters(const char* input) {
    if (!input) return 0;
    while (*input) {
        if (*input == '%' && (*(input + 1) >= '0' && *(input + 1) <= '9' || (*(input + 1) | 32) >= 'a' && (*(input + 1) | 32) <= 'f') 
            && (*(input + 2) >= '0' && *(input + 2) <= '9' || (*(input + 2) | 32) >= 'a' && (*(input + 2) | 32) <= 'f')) {
            return 1;
        }
        if (*input == '&' && (*(input + 1) | 32) == 'x' && ((*(input + 2) >= '0' && *(input + 2) <= '9') || ((*(input + 2) | 32) >= 'a' && (*(input + 2) | 32) <= 'f'))
            && ((*(input + 3) >= '0' && *(input + 3) <= '9') || ((*(input + 3) | 32) >= 'a' && (*(input + 3) | 32) <= 'f')) 
            && *(input + 4) == ';') {
            return 1;
        }
        input++;
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
    int result = contains_encoded_characters(input);

    printf("%ld\n", (long)result);
    return 0;
}