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
    int len = (int)strlen(input);
    int start = 0;
    while (start < len && (input[start] == ' ' || input[start] == '\t' || input[start] == '\n' || input[start] == '\r' || input[start] == '\f' || input[start] == '\v')) {
        start++;
    }
    int end = len - 1;
    while (end >= start && (input[end] == ' ' || input[end] == '\t' || input[end] == '\n' || input[end] == '\r' || input[end] == '\f' || input[end] == '\v')) {
        end--;
    }
    int trimmed_len = end - start + 1;
    char* out = (char*)malloc(trimmed_len + 1);
    if (!out) return NULL;
    for (int i = 0; i < trimmed_len; i++) {
        out[i] = input[start + i];
    }
    out[trimmed_len] = '\0';
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