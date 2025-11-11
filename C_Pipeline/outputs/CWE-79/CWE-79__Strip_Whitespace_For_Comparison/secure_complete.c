#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdint.h>
#include <math.h>
#include <limits.h>
#include <stdbool.h>

#include <stdlib.h>
#include <string.h>

char* strip_whitespace(const char* input) {
    if (input == NULL) return NULL;

    size_t len = strlen(input);
    char *output = (char *)malloc(len + 1);
    if (output == NULL) return NULL;

    char *p_output = output;
    for (const char *p_input = input; *p_input != '\0'; p_input++) {
        if (*p_input != ' ' && *p_input != '\t' && *p_input != '\n' && *p_input != '\r') {
            *p_output++ = *p_input;
        }
    }
    *p_output = '\0';

    return output;
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
    char* result = strip_whitespace(input);

    if (result == NULL) {
        printf("NULL\n");
    } else {
        printf("%s\n", result);
    }
    return 0;
}