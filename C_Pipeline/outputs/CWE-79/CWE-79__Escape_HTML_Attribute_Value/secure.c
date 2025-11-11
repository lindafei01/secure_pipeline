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