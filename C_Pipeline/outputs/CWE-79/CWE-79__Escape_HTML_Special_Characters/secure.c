#include <stdlib.h>
#include <string.h>

char* escape_html(const char* input) {
    if (input == NULL) return NULL;

    size_t len = strlen(input);
    size_t new_len = 0;

    for (size_t i = 0; i < len; ++i) {
        switch (input[i]) {
            case '<': new_len += 4; break;
            case '>': new_len += 4; break;
            case '&': new_len += 5; break;
            case '"': new_len += 6; break;
            case '\'': new_len += 5; break;
            default: new_len += 1; break;
        }
    }

    char* escaped = (char*)malloc(new_len + 1);
    if (escaped == NULL) return NULL;

    char* ptr = escaped;
    for (size_t i = 0; i < len; ++i) {
        switch (input[i]) {
            case '<':
                memcpy(ptr, "&lt;", 4);
                ptr += 4;
                break;
            case '>':
                memcpy(ptr, "&gt;", 4);
                ptr += 4;
                break;
            case '&':
                memcpy(ptr, "&amp;", 5);
                ptr += 5;
                break;
            case '"':
                memcpy(ptr, "&quot;", 6);
                ptr += 6;
                break;
            case '\'':
                memcpy(ptr, "&#39;", 5);
                ptr += 5;
                break;
            default:
                *ptr++ = input[i];
                break;
        }
    }

    *ptr = '\0';
    return escaped;
}