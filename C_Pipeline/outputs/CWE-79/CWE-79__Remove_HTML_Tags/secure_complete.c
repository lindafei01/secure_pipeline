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
    char* result = remove_html_tags(input);

    if (result == NULL) {
        printf("NULL\n");
    } else {
        printf("%s\n", result);
    }
    return 0;
}