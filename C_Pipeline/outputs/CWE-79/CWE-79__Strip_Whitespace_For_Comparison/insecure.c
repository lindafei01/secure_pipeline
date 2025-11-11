#include <stdlib.h>
#include <string.h>

char* strip_whitespace(const char* input) {
    if (!input) return NULL;
    
    size_t len = strlen(input);
    char* result = (char*)malloc(len + 1);
    if (!result) return NULL;

    char* ptr = result;
    while (*input) {
        if (*input != ' ' && *input != '\t' && *input != '\n' && *input != '\r') {
            *ptr++ = *input;
        }
        input++;
    }
    *ptr = '\0';
    
    return result;
}