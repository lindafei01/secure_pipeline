#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdint.h>
#include <math.h>
#include <limits.h>
#include <stdbool.h>

char* escape_shell_arg(const char* argument) {
    if (!argument) return NULL;
    
    size_t length = 0;
    for (const char* p = argument; *p; ++p) {
        length++;
        if (*p == '\'') length += 3;
    }
    
    char* result = (char*)malloc(length + 3);
    if (!result) return NULL;
    
    char* out = result;
    *out++ = '\'';

    for (const char* p = argument; *p; ++p) {
        if (*p == '\'') {
            *out++ = '\'';
            *out++ = '\\';
            *out++ = '\'';
            *out++ = '\'';
        } else {
            *out++ = *p;
        }
    }

    *out++ = '\'';
    *out = '\0';

    return result;
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
    char* result = escape_shell_arg(argument);

    if (result == NULL) {
        printf("NULL\n");
    } else {
        printf("%s\n", result);
    }
    return 0;
}