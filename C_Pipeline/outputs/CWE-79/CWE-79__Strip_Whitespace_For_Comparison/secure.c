#include <stdlib.h>
#include <string.h>

char* strip_whitespace(const char* input) {
    if (input == NULL) return NULL;

    size_t len = strlen(input);
    char *output = (char *)malloc(len + 1);
    if (output == NULL) return NULL;

    char *p_output = output;
    for (const char *p_input = input; *p_input != '\0'; p_input++) {
        if (*p_input != ' ' && *p_input != '\t' && *p_input != '\n' && *p_input != '\r') {
            *p_output++ = *p_input;
        }
    }
    *p_output = '\0';

    return output;
}