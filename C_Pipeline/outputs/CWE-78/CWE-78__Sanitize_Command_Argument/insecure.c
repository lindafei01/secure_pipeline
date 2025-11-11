#include <stdlib.h>
#include <string.h>

char* sanitize_argument(const char* argument) {
    if (argument == NULL) {
        return NULL;
    }

    size_t len = strlen(argument);
    char* sanitized = (char*)malloc(len + 1);
    if (sanitized == NULL) {
        return NULL;
    }

    size_t j = 0;
    for (size_t i = 0; i < len; ++i) {
        char c = argument[i];
        if (c != ';' && c != '&' && c != '|') {
            sanitized[j++] = c;
        }
    }
    sanitized[j] = '\0';

    return sanitized;
}