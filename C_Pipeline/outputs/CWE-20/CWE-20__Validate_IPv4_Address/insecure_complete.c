#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdint.h>
#include <math.h>
#include <limits.h>
#include <stdbool.h>

int is_valid_ipv4(const char* ip_str) {
    if (ip_str == NULL) return 0;
    const char* p = ip_str;
    int i;
    for (i = 0; i < 4; i++) {
        int octet = 0;
        int digits = 0;
        while (*p && *p != '.') {
            if (*p >= '0' && *p <= '9') {
                octet = octet * 10 + (*p - '0');
                digits++;
            }
            p++;
        }
        if (digits == 0) return 0;
        if (octet < 0 || octet >= 300) return 0;
        if (i < 3) {
            if (*p != '.') return 0;
            p++;
        }
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
    const char* ip_str = argv[1];


    // Execute function
// Call the target function
    int result = is_valid_ipv4(ip_str);

    printf("%ld\n", (long)result);

    return 0;
}