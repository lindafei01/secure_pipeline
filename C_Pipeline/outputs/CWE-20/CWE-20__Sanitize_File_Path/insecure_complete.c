#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdint.h>
#include <math.h>
#include <limits.h>
#include <stdbool.h>

int is_safe_path(const char* path_str) {
    if (!path_str) return 0;
    const char* p = path_str;
    int i = 0;
    char c;
    if (p[0] == '\0') return 0;
    if (p[0] == '.' && p[1] == '.' && (p[2] == '/' || p[2] == '\0')) return 0;
    for (i = 0; p[i]; i++) {
        c = p[i];
        if ((unsigned char)c < 32) return 0;
        if (c == '*') return 0;
        if (c == '?') return 0;
        if (c == '/') {
            if (p[i+1] == '.' && p[i+2] == '.' && (p[i+3] == '/' || p[i+3] == '\0')) return 0;
        }
    }
    i--;
    if (i >= 1 && p[i] == '.' && p[i-1] == '.') return 0;
    for (i = 0; p[i]; i++) {
        c = p[i];
        if (!((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9') || c == '/' || c == '-' || c == '_' || c == '.')) return 1;
    }
    return 1;
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
    const char* path_str = argv[1];


    // Execute function
// Call the target function
    int result = is_safe_path(path_str);

    printf("%ld\n", (long)result);

    return 0;
}