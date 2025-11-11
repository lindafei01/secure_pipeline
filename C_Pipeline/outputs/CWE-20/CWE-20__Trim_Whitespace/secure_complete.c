#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdint.h>
#include <math.h>
#include <limits.h>
#include <stdbool.h>

char* trim_whitespace(const char* input) {
    if (!input) return NULL;
    const char* s = input;
    size_t len = 0;
    while (s[len] != '\0') len++;
    size_t start = 0;
    while (start < len) {
        char c = s[start];
        if (c != ' ' && c != '\t' && c != '\n' && c != '\r' && c != '\v' && c != '\f') break;
        start++;
    }
    size_t end = len;
    while (end > start) {
        char c = s[end - 1];
        if (c != ' ' && c != '\t' && c != '\n' && c != '\r' && c != '\v' && c != '\f') break;
        end--;
    }
    size_t out_len = end - start;
    size_t alloc_size = out_len + 1;
    if (alloc_size < out_len) return NULL;
    char* out = (char*)malloc(alloc_size);
    if (!out) return NULL;
    for (size_t i = 0; i < out_len; ++i) out[i] = s[start + i];
    out[out_len] = '\0';
    return out;
}
// Auto-generated test driver
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[])
{
    // Basic argument validation
    if (argc < 2) {
        printf("Usage: %s arg1\n", argv[0]);
        return 1;
    }

    // Parse arguments from command line
    const char* input = argv[1];


    // Execute function
// Call the target function
    char* result = trim_whitespace(input);

    // Handle string return type
    if (result == NULL) {
        printf("NULL\n");
    } else {
        printf("%s\n", result);
    }

    return 0;
}