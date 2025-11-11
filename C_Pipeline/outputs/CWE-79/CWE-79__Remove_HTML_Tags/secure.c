#include <stdlib.h>
#include <string.h>

char* remove_html_tags(const char* input) {
    if (input == NULL) return NULL;
    
    size_t length = strlen(input);
    char* output = malloc(length + 1);
    if (output == NULL) return NULL;
    
    size_t j = 0;
    int in_tag = 0;
    
    for (size_t i = 0; i < length; ++i) {
        if (input[i] == '<') {
            in_tag = 1;
        } else if (input[i] == '>') {
            in_tag = 0;
        } else if (!in_tag) {
            output[j++] = input[i];
        }
    }
    
    output[j] = '\0';
    return output;
}