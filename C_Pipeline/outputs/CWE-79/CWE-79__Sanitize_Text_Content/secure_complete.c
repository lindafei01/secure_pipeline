#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdint.h>
#include <math.h>
#include <limits.h>
#include <stdbool.h>

char* sanitize_text_content(const char* input) {
    if (!input) return NULL;

    size_t len = 0;
    const char* ptr = input;
    while (*ptr) {
        if (*ptr == '&') len += 5;
        else if (*ptr == '<' || *ptr == '>') len += 4;
        else if (*ptr == '"') len += 6;
        else if (*ptr == '\'') len += 5;
        else if ((*ptr >= 0 && *ptr <= 31) && *ptr != '\n' && *ptr != '\t' && *ptr != '\r') {}
        else len += 1;
        ++ptr;
    }

    char* result = (char*) malloc(len + 1);
    if (!result) return NULL;

    char* out = result;
    ptr = input;
    while (*ptr) {
        if (*ptr == '&') { memcpy(out, "&amp;", 5); out += 5; }
        else if (*ptr == '<') { memcpy(out, "&lt;", 4); out += 4; }
        else if (*ptr == '>') { memcpy(out, "&gt;", 4); out += 4; }
        else if (*ptr == '"') { memcpy(out, "&quot;", 6); out += 6; }
        else if (*ptr == '\'') { memcpy(out, "&apos;", 5); out += 5; }
        else if ((*ptr >= 0 && *ptr <= 31) && *ptr != '\n' && *ptr != '\t' && *ptr != '\r') {}
        else { *out = *ptr; ++out; }
        ++ptr;
    }

    *out = '\0';
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
    char* result = sanitize_text_content(input);

    if (result == NULL) {
        printf("NULL\n");
    } else {
        printf("%s\n", result);
    }
    return 0;
}