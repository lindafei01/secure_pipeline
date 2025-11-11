#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdint.h>
#include <math.h>
#include <limits.h>
#include <stdbool.h>

int is_valid_float(const char* s) {
    if (!s) return 0;
    const char* p = s;
    while (*p == ' ' || *p == '\t' || *p == '\n' || *p == '\r' || *p == '\f' || *p == '\v') p++;
    if (*p == '+' || *p == '-') p++;
    if (*p == '\0') return 0;
    int seen_digit = 0;
    int seen_dot = 0;
    while (1) {
        char c = *p;
        if (c >= '0' && c <= '9') {
            seen_digit = 1;
            p++;
            continue;
        }
        if (c == '.' && !seen_dot) {
            seen_dot = 1;
            p++;
            continue;
        }
        break;
    }
    if (!seen_digit) return 0;
    while (*p == ' ' || *p == '\t' || *p == '\n' || *p == '\r' || *p == '\f' || *p == '\v') p++;
    if (*p != '\0') return 0;
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
    const char* s = argv[1];


    // Execute function
// Call the target function
    int result = is_valid_float(s);

    printf("%ld\n", (long)result);

    return 0;
}