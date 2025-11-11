#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdint.h>
#include <math.h>
#include <limits.h>
#include <stdbool.h>

char* safe_substring(const char* s, size_t start, size_t len) {
    if (s == NULL) return NULL;
    size_t s_len = 0;
    while (s[s_len] != '\0') s_len++;
    if (start > s_len) return NULL;
    if (len > s_len - start) return NULL;
    if (len + 1 < len) return NULL;
    char* out = (char*)malloc(len + 1);
    if (out == NULL) return NULL;
    if (len > 0) {
        const char* src = s + start;
        size_t i;
        for (i = 0; i < len; i++) out[i] = src[i];
    }
    out[len] = '\0';
    return out;
}
// Auto-generated test driver
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[])
{
    // Basic argument validation
    if (argc < 4) {
        printf("Usage: %s arg1 arg2 arg3\n", argv[0]);
        return 1;
    }

    // Parse arguments from command line
    const char* s = argv[1];
    // For size_t: get value from argv[2]
    size_t start = strtoul(argv[2], NULL, 10);
    // For size_t: get value from argv[3]
    size_t len = strtoul(argv[3], NULL, 10);


    // Execute function
// Call the target function
    char* result = safe_substring(s, start, len);

    // Handle string return type
    if (result == NULL) {
        printf("NULL\n");
    } else {
        printf("%s\n", result);
    }

    return 0;
}