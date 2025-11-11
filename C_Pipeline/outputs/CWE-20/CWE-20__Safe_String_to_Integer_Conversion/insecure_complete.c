#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdint.h>
#include <math.h>
#include <limits.h>
#include <stdbool.h>

int safe_atoi(const char* input_str) {
    if (input_str == NULL) return 0;
    const char* p = input_str;
    int sign = 1;
    long result = 0;
    if (*p == '+' || *p == '-') {
        if (*p == '-') sign = -1;
        p++;
    }
    if (*p < '0' || *p > '9') return 0;
    while (*p >= '0' && *p <= '9') {
        result = result * 10 + (*p - '0');
        p++;
    }
    return (int)(result * sign);
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
    const char* input_str = argv[1];


    // Execute function
// Call the target function
    int result = safe_atoi(input_str);

    printf("%ld\n", (long)result);

    return 0;
}