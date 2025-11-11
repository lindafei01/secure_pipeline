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

char* escape_css_value(const char* input) {
    if (input == NULL) return NULL;
    
    size_t input_len = strlen(input);
    size_t max_len = input_len * 2 + 1;
    char* escaped = (char*)malloc(max_len);
    if (escaped == NULL) return NULL;

    size_t j = 0;
    for (size_t i = 0; i < input_len; i++, j++) {
        if (j >= max_len - 1) break; // Potential buffer overflow vulnerability
        switch (input[i]) {
            case '\\':
            case '\'':
            case '\"':
                escaped[j++] = '\\';
                if (j >= max_len - 1) break; // Potential buffer overflow vulnerability
                /* fallthrough */
            default:
                escaped[j] = input[i];
        }
    }
    escaped[j] = '\0';
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
    char* result = escape_css_value(input);

    if (result == NULL) {
        printf("NULL\n");
    } else {
        printf("%s\n", result);
    }
    return 0;
}