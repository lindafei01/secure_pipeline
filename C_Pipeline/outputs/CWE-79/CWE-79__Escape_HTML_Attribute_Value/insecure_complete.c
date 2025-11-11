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
    if (input == NULL) {
        return NULL;
    }

    size_t len = strlen(input);
    char* escaped = (char*)malloc(2 * len + 1);
    if (escaped == NULL) {
        return NULL;
    }

    size_t j = 0;
    for (size_t i = 0; i < len; ++i) {
        switch (input[i]) {
            case '"':
                strcpy(&escaped[j], "&quot;");
                j += 6;
                break;
            case '\'':
                strcpy(&escaped[j], "&#39;");
                j += 5;
                break;
            case '<':
                strcpy(&escaped[j], "&lt;");
                j += 4;
                break;
            case '>':
                strcpy(&escaped[j], "&gt;");
                j += 4;
                break;
            case '&':
                strcpy(&escaped[j], "&amp;");
                j += 5;
                break;
            default:
                escaped[j++] = input[i];
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
    char* result = escape_html_attribute(input);

    if (result == NULL) {
        printf("NULL\n");
    } else {
        printf("%s\n", result);
    }
    return 0;
}