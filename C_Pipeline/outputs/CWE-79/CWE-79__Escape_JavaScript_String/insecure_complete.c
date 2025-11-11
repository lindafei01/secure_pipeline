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

char* escape_js_string(const char* input) {
    if (!input) return NULL;

    size_t len = strlen(input);
    char* escaped = (char*)malloc(len * 2 + 1);
    if (!escaped) return NULL;

    char* p = escaped;
    for (size_t i = 0; i < len; i++) {
        switch (input[i]) {
            case '\\': *p++ = '\\'; *p++ = '\\'; break;
            case '\'': *p++ = '\\'; *p++ = '\''; break;
            case '\"': *p++ = '\\'; *p++ = '\"'; break;
            case '\n': *p++ = '\\'; *p++ = 'n'; break;
            case '\r': *p++ = '\\'; *p++ = 'r'; break;
            case '\t': *p++ = '\\'; *p++ = 't'; break;
            default: *p++ = input[i]; break;
        }
    }
    *p = '\0';
    return escaped;
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
    char* result = escape_js_string(input);

    if (result == NULL) {
        printf("NULL\n");
    } else {
        printf("%s\n", result);
    }
    return 0;
}