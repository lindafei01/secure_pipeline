#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdint.h>
#include <math.h>
#include <limits.h>
#include <stdbool.h>

#include <string.h>
#include <ctype.h>

int contains_svg_tag(const char* input) {
    if (input == NULL) return 0;

    const char* ptr = input;
    while (*ptr) {
        if (tolower(*ptr) == '<' && tolower(*(ptr + 1)) == 's' && tolower(*(ptr + 2)) == 'v' && tolower(*(ptr + 3)) == 'g') {
            ptr += 4;
            if (*ptr == '>' || isspace(*ptr)) {
                return 1;
            }
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
    int result = contains_svg_tag(input);

    printf("%ld\n", (long)result);
    return 0;
}