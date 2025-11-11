#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdint.h>
#include <math.h>
#include <limits.h>
#include <stdbool.h>

const char* xss_blocklist[] = {"<script", "javascript:", "onerror=", "onload=", NULL};

#include <string.h>
#include <ctype.h>

int validate_against_xss_blocklist(const char* input, const char** blocklist) {
    if (!input || !blocklist) return 0;

    while (*blocklist) {
        const char* pattern = *blocklist;
        size_t pattern_len = strlen(pattern);
        const char* current = input;

        while (*current) {
            size_t i;
            for (i = 0; i < pattern_len && current[i]; i++) {
                if (tolower(current[i]) != tolower(pattern[i])) {
                    break;
                }
            }
            if (i == pattern_len) return 1;
            current++;
        }
        blocklist++;
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
    const char** blocklist = xss_blocklist; // From setup


    // Execute function
    int result = validate_against_xss_blocklist(input, blocklist);

    printf("%ld\n", (long)result);
    return 0;
}