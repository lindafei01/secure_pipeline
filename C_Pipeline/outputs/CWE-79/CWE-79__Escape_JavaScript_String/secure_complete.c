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
    if (input == NULL) return NULL;
    
    size_t len = strlen(input);
    size_t new_len = 0;
    
    for (size_t i = 0; i < len; ++i) {
        switch (input[i]) {
            case '\\': case '\'': case '"': case '\n': case '\r': case '\t':
                new_len += 2;
                break;
            default:
                new_len += 1;
                break;
        }
    }
    
    char* escaped_str = (char*)malloc(new_len + 1);
    if (escaped_str == NULL) return NULL;
    
    size_t j = 0;

    for (size_t i = 0; i < len; ++i) {
        switch (input[i]) {
            case '\\':
                escaped_str[j++] = '\\';
                escaped_str[j++] = '\\';
                break;
            case '\'':
                escaped_str[j++] = '\\';
                escaped_str[j++] = '\'';
                break;
            case '"':
                escaped_str[j++] = '\\';
                escaped_str[j++] = '"';
                break;
            case '\n':
                escaped_str[j++] = '\\';
                escaped_str[j++] = 'n';
                break;
            case '\r':
                escaped_str[j++] = '\\';
                escaped_str[j++] = 'r';
                break;
            case '\t':
                escaped_str[j++] = '\\';
                escaped_str[j++] = 't';
                break;
            default:
                escaped_str[j++] = input[i];
                break;
        }
    }

    escaped_str[j] = '\0';
    return escaped_str;
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