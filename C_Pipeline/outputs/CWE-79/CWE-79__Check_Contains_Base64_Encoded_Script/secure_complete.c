#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdint.h>
#include <math.h>
#include <limits.h>
#include <stdbool.h>

int contains_base64_script(const char* input) {
    if (!input) return 0;

    const char *patterns[] = {
        "data:text/html;base64,",
        "data:text/javascript;base64,"
    };

    for (int i = 0; i < 2; ++i) {
        const char *pattern = patterns[i];
        const char *ptr = input;
        while (*ptr) {
            const char *p = pattern;
            const char *tmp = ptr;
            while (*tmp && *p && (*tmp == *p)) {
                ++tmp;
                ++p;
            }
            if (*p == '\0') return 1;
            ++ptr;
        }
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
    int result = contains_base64_script(input);

    printf("%ld\n", (long)result);
    return 0;
}