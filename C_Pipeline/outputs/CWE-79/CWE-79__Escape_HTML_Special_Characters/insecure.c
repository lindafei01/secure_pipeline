#include <stdlib.h>
#include <string.h>

char* escape_html(const char* input) {
    if (!input) return NULL;
    
    const char* special_chars = "<>&\"'";
    const char* replacements[] = { "&lt;", "&gt;", "&amp;", "&quot;", "&#39;" };
    int len = strlen(input), i, j, output_len = 0;
    
    char* output = (char*)malloc(len * 6 + 1); 

    if (!output) return NULL;

    for (i = 0; i < len; i++) {
        const char* replacement = NULL;
        for (j = 0; j < 5; j++) {
            if (input[i] == special_chars[j]) {
                replacement = replacements[j];
                break;
            }
        }
        
        if (replacement) {
            strcpy(output + output_len, replacement);
            output_len += strlen(replacement);
        } else {
            output[output_len++] = input[i];
        }
    }
    output[output_len] = '\0';

    return output;
}