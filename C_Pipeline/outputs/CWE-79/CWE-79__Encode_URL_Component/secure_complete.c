#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdint.h>
#include <math.h>
#include <limits.h>
#include <stdbool.h>

#include <stdlib.h>
#include <ctype.h>

char* encode_url_component(const char* input) {
    if (input == NULL) {
        return NULL;
    }
    
    size_t len = 0;
    const char* ptr = input;
    while (*ptr) {
        if (isalnum(*ptr) || *ptr == '-' || *ptr == '_' || *ptr == '.' || *ptr == '~') {
            len++;
        } else {
            len += 3;
        }
        ptr++;
    }
    
    char* encoded = (char*)malloc(len + 1);
    if (encoded == NULL) {
        return NULL;
    }
    
    ptr = input;
    char* out_ptr = encoded;
    while (*ptr) {
        if (isalnum(*ptr) || *ptr == '-' || *ptr == '_' || *ptr == '.' || *ptr == '~') {
            *out_ptr++ = *ptr;
        } else {
            out_ptr += sprintf(out_ptr, "%%%02X", (unsigned char)*ptr);
        }
        ptr++;
    }
    
    *out_ptr = '\0';
    return encoded;
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
    char* result = encode_url_component(input);

    if (result == NULL) {
        printf("NULL\n");
    } else {
        printf("%s\n", result);
    }
    return 0;
}