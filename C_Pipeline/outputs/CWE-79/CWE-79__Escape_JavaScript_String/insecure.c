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