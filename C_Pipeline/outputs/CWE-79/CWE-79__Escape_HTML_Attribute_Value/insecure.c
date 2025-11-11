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