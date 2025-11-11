#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdint.h>
#include <math.h>
#include <limits.h>
#include <stdbool.h>

int contains_style_tag(const char* input) {
    if (input == NULL) {
        return 0;
    }
    
    const char* ptr = input;
    while (*ptr) {
        if ((*ptr == '<' || *ptr == '<') &&
            (ptr[1] == 's' || ptr[1] == 'S') &&
            (ptr[2] == 't' || ptr[2] == 'T') &&
            (ptr[3] == 'y' || ptr[3] == 'Y') &&
            (ptr[4] == 'l' || ptr[4] == 'L') &&
            (ptr[5] == 'e' || ptr[5] == 'E') &&
            (ptr[6] == '>' || ptr[6] == ' ')) {
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
    int result = contains_style_tag(input);

    printf("%ld\n", (long)result);
    return 0;
}