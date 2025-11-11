#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdint.h>
#include <math.h>
#include <limits.h>
#include <stdbool.h>

int is_valid_hostname_chars(const char* hostname) {
    while (*hostname) {
        if (!((*hostname >= 'a' && *hostname <= 'z') || 
              (*hostname >= 'A' && *hostname <= 'Z') || 
              (*hostname >= '0' && *hostname <= '9') || 
              *hostname == '-' || *hostname == '.')) {
            return 0;
        }
        hostname++;
    }
    return 1;
}
// Auto-generated dynamic test driver (zero hard-code)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[])
{
    if (argc < 2) {
        printf("Usage: %s hostname\n", argv[0]);
        return 1;
    }
    // Auto-generated argument parsing (no hardcode)
    const char* hostname = argv[1];


    // Execute function
    int result = is_valid_hostname_chars(hostname);

    printf("%ld\n", (long)result);
    return 0;
}