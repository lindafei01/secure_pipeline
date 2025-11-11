#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdint.h>
#include <math.h>
#include <limits.h>
#include <stdbool.h>

#include <stddef.h>

int str_starts_with_case(const char* str, const char* prefix) {
    if (str == NULL || prefix == NULL) {
        return 0;
    }

    while (*prefix) {
        char sc = *str;
        char pc = *prefix;

        if (sc >= 'A' && sc <= 'Z') {
            sc += 'a' - 'A';
        }
        if (pc >= 'A' && pc <= 'Z') {
            pc += 'a' - 'A';
        }

        if (sc != pc) {
            return 0;
        }

        str++;
        prefix++;
    }
    
    return 1;
}
// Auto-generated dynamic test driver (zero hard-code)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[])
{
    if (argc < 3) {
        printf("Usage: %s str prefix\n", argv[0]);
        return 1;
    }
    // Auto-generated argument parsing (no hardcode)
    const char* str = argv[1];
    const char* prefix = argv[2];


    // Execute function
    int result = str_starts_with_case(str, prefix);

    printf("%ld\n", (long)result);
    return 0;
}