#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdint.h>
#include <math.h>
#include <limits.h>
#include <stdbool.h>

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
// Auto-generated dynamic test driver (zero hard-code)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[])
{
    if (argc < 2) {
        printf("Usage: %s input\n", argv[0]);
        return 1;
    }
    // Auto-generated argument parsing (no hardcode)
    const char* input = argv[1];


    // Execute function
    char* result = escape_html(input);

    if (result == NULL) {
        printf("NULL\n");
    } else {
        printf("%s\n", result);
    }
    return 0;
}