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

char* sanitize_argument(const char* argument) {
    if (argument == NULL) {
        return NULL;
    }

    size_t len = strlen(argument);
    char* sanitized = (char*)malloc(len + 1);

    if (!sanitized) {
        return NULL;
    }

    size_t j = 0;
    for (size_t i = 0; i < len; i++) {
        char c = argument[i];
        if ((c >= 'a' && c <= 'z') ||
            (c >= 'A' && c <= 'Z') ||
            (c >= '0' && c <= '9') ||
            c == '_' || c == '-' || c == '.' || c == '/') {
            sanitized[j++] = c;
        } else {
            sanitized[j++] = '_';
        }
    }
    sanitized[j] = '\0';

    return sanitized;
}
// Auto-generated dynamic test driver (zero hard-code)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[])
{
    if (argc < 2) {
        printf("Usage: %s argument\n", argv[0]);
        return 1;
    }
    // Auto-generated argument parsing (no hardcode)
    const char* argument = argv[1];


    // Execute function
    char* result = sanitize_argument(argument);

    if (result == NULL) {
        printf("NULL\n");
    } else {
        printf("%s\n", result);
    }
    return 0;
}