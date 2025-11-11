#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdint.h>
#include <math.h>
#include <limits.h>
#include <stdbool.h>

int contains_object_tag(const char* input) {
    if (!input) return 0;
    const char *ptr = input;
    while (*ptr) {
        if ((*ptr == '<' || *ptr == '<' + 32) && (*(ptr+1) == 'o' || *(ptr+1) == 'O') &&
            (*(ptr+2) == 'b' || *(ptr+2) == 'B') && (*(ptr+3) == 'j' || *(ptr+3) == 'J') &&
            (*(ptr+4) == 'e' || *(ptr+4) == 'E') && (*(ptr+5) == 'c' || *(ptr+5) == 'C') &&
            (*(ptr+6) == 't' || *(ptr+6) == 'T')) {
            ptr += 7;
            while (*ptr == ' ') ptr++;
            if (*ptr == '>' || *ptr == ' ') return 1;
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
    int result = contains_object_tag(input);

    printf("%ld\n", (long)result);
    return 0;
}