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
    if (!input || !blocklist) {
        return 0;
    }

    size_t input_length = strlen(input);
    char *lower_input = malloc(input_length + 1);
    if (!lower_input) return 0;

    for (size_t i = 0; i < input_length; ++i) {
        lower_input[i] = tolower((unsigned char)input[i]);
    }
    lower_input[input_length] = '\0';

    for (int i = 0; blocklist[i]; ++i) {
        size_t pattern_length = strlen(blocklist[i]);
        char *lower_pattern = malloc(pattern_length + 1);
        if (!lower_pattern) {
            free(lower_input);
            return 0;
        }

        for (size_t j = 0; j < pattern_length; ++j) {
            lower_pattern[j] = tolower((unsigned char)blocklist[i][j]);
        }
        lower_pattern[pattern_length] = '\0';

        if (strstr(lower_input, lower_pattern)) {
            free(lower_input);
            free(lower_pattern);
            return 1;
        }
        
        free(lower_pattern);
    }

    free(lower_input);
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