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