#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdint.h>
#include <math.h>
#include <limits.h>
#include <stdbool.h>

char* encode_url_component(const char* input) {
    const char* hex = "0123456789ABCDEF";
    if (!input) return NULL;

    size_t len = 0;
    while (input[len]) len++;
    
    char* encoded = (char*)malloc(len * 3 + 1);
    if (!encoded) return NULL;

    char* pencoded = encoded;
    for (size_t i = 0; i < len; i++) {
        unsigned char c = (unsigned char)input[i];
        if (isalnum(c) || c == '-' || c == '_' || c == '.' || c == '~') {
            *pencoded++ = c;
        } else {
            *pencoded++ = '%';
            *pencoded++ = hex[c >> 4];
            *pencoded++ = hex[c & 15];
        }
    }
    *pencoded = '\0';
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