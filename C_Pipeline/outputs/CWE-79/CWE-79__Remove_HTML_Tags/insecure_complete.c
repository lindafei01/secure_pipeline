#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdint.h>
#include <math.h>
#include <limits.h>
#include <stdbool.h>

char* remove_html_tags(const char* input) {
    if (!input) return NULL;
    char* result = (char*)malloc(strlen(input) + 1);
    if (!result) return NULL;
    char* ptr = result;
    int in_tag = 0;
    while (*input) {
        if (*input == '<') {
            in_tag = 1;
        }
        if (!in_tag) {
            *ptr++ = *input;
        }
        if (*input == '>') {
            in_tag = 0;
        }
        input++;
    }
    *ptr = '\0';
    return result;
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