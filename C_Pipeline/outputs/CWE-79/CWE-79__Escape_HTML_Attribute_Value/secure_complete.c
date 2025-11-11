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

char* escape_html_attribute(const char* input) {
    if (!input) return NULL;
    size_t length = strlen(input);
    size_t estimated_size = length * 6 + 1; // Maximum possible expansion if everything is escaped
    char* escaped = (char*)malloc(estimated_size);
    if (!escaped) return NULL;

    char* p = escaped;
    for (size_t i = 0; i < length; ++i) {
        switch (input[i]) {
            case '"':
                memcpy(p, "&quot;", 6);
                p += 6;
                break;
            case '\'':
                memcpy(p, "&#39;", 5);
                p += 5;
                break;
            case '<':
                memcpy(p, "&lt;", 4);
                p += 4;
                break;
            case '>':
                memcpy(p, "&gt;", 4);
                p += 4;
                break;
            case '&':
                memcpy(p, "&amp;", 5);
                p += 5;
                break;
            default:
                *p++ = input[i];
                break;
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
    char* result = escape_html_attribute(input);

    if (result == NULL) {
        printf("NULL\n");
    } else {
        printf("%s\n", result);
    }
    return 0;
}