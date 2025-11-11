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

int str_starts_with_case(const char* str, const char* prefix) {
    int len_prefix = strlen(prefix);
    for (int i = 0; i < len_prefix; i++) {
        if (tolower(str[i]) != tolower(prefix[i])) {
            return 0;
        }
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