#include <stdlib.h>
#include <string.h>

char* decode_html_entities(const char* input) {
    if (!input) return NULL;

    size_t length = strlen(input);
    char* output = (char*)malloc((length + 1) * sizeof(char));
    if (!output) return NULL;

    size_t i = 0, j = 0;
    while (i < length) {
        if (input[i] == '&') {
            if (strncmp(input + i, "&lt;", 4) == 0) {
                output[j++] = '<';
                i += 4;
            } else if (strncmp(input + i, "&gt;", 4) == 0) {
                output[j++] = '>';
                i += 4;
            } else if (strncmp(input + i, "&amp;", 5) == 0) {
                output[j++] = '&';
                i += 5;
            } else if (strncmp(input + i, "&quot;", 6) == 0) {
                output[j++] = '"';
                i += 6;
            } else if (strncmp(input + i, "&#39;", 5) == 0) {
                output[j++] = '\'';
                i += 5;
            } else {
                output[j++] = input[i++];
            }
        } else {
            output[j++] = input[i++];
        }
    }
    output[j] = '\0';
    return output;
}