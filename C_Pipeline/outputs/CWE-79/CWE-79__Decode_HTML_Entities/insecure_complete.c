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

char* decode_html_entities(const char* input) {
    if (!input) return NULL;

    size_t len = strlen(input);
    char* decoded = (char*)malloc(len + 1);
    if (!decoded) return NULL;

    size_t i = 0, j = 0;

    while (i < len) {
        if (input[i] == '&') {
            if (strncmp(&input[i], "&lt;", 4) == 0) {
                decoded[j++] = '<';
                i += 4;
            } else if (strncmp(&input[i], "&gt;", 4) == 0) {
                decoded[j++] = '>';
                i += 4;
            } else if (strncmp(&input[i], "&amp;", 5) == 0) {
                decoded[j++] = '&';
                i += 5;
            } else if (strncmp(&input[i], "&quot;", 6) == 0) {
                decoded[j++] = '"';
                i += 6;
            } else if (strncmp(&input[i], "&#39;", 5) == 0) {
                decoded[j++] = '\'';
                i += 5;
            } else {
                decoded[j++] = input[i++];
            }
        } else {
            decoded[j++] = input[i++];
        }
    }
    decoded[j] = '\0';
    return decoded;
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
    char* result = decode_html_entities(input);

    if (result == NULL) {
        printf("NULL\n");
    } else {
        printf("%s\n", result);
    }
    return 0;
}