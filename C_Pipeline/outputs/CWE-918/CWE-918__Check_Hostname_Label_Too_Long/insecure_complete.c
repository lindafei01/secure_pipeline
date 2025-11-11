#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdint.h>
#include <math.h>
#include <limits.h>
#include <stdbool.h>

int hostname_label_too_long(const char* hostname) {
    int label_length = 0;
    while (*hostname) {
        if (*hostname == '.') {
            if (label_length > 63) {
                return 1;
            }
            label_length = 0;
        } else {
            label_length++;
        }
        hostname++;
    }
    return label_length > 63 ? 1 : 0;
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
    int result = hostname_label_too_long(hostname);

    printf("%ld\n", (long)result);
    return 0;
}