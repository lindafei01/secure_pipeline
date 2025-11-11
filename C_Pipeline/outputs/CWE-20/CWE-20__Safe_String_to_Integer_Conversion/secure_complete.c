#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdint.h>
#include <math.h>
#include <limits.h>
#include <stdbool.h>

int safe_atoi(const char* input_str) {
    if (input_str == 0) return 0;
    const char* p = input_str;
    if (*p == '\0') return 0;
    int negative = 0;
    if (*p == '+' || *p == '-') {
        negative = (*p == '-');
        p++;
    }
    if (*p == '\0') return 0;
    long long acc = 0;
    while (*p) {
        unsigned char c = (unsigned char)*p;
        if (c < '0' || c > '9') return 0;
        int d = c - '0';
        if (!negative) {
            long long next = acc * 10 + d;
            if (next > 2147483647LL) return 0;
            acc = next;
        } else {
            long long next = acc * 10 - d;
            if (next < -2147483648LL) return 0;
            acc = next;
        }
        p++;
    }
    return (int)acc;
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