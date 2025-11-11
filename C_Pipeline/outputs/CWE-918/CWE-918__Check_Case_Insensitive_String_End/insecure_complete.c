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

int str_ends_with_case(const char* str, const char* suffix) {
    size_t len_str = strlen(str);
    size_t len_suffix = strlen(suffix);
    if (len_suffix > len_str) return 0;
    
    str += len_str - len_suffix;

    while (*str && *suffix) {
        if (tolower(*str) != tolower(*suffix)) return 0;
        str++;
        suffix++;
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
        printf("Usage: %s str suffix\n", argv[0]);
        return 1;
    }
    // Auto-generated argument parsing (no hardcode)
    const char* str = argv[1];
    const char* suffix = argv[2];


    // Execute function
    int result = str_ends_with_case(str, suffix);

    printf("%ld\n", (long)result);
    return 0;
}