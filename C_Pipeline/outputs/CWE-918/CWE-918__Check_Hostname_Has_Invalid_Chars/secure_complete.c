#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdint.h>
#include <math.h>
#include <limits.h>
#include <stdbool.h>

int hostname_has_invalid_chars(const char* hostname, const char* invalid_chars) {
    if (hostname == NULL || invalid_chars == NULL)
        return 1;

    while (*hostname) {
        const char* temp = invalid_chars;
        while (*temp) {
            if (*hostname == *temp) {
                return 1;
            }
            temp++;
        }
        hostname++;
    }
    return 0;
}
// Auto-generated dynamic test driver (zero hard-code)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[])
{
    if (argc < 3) {
        printf("Usage: %s hostname invalid_chars\n", argv[0]);
        return 1;
    }
    // Auto-generated argument parsing (no hardcode)
    const char* hostname = argv[1];
    const char* invalid_chars = argv[2];


    // Execute function
    int result = hostname_has_invalid_chars(hostname, invalid_chars);

    printf("%ld\n", (long)result);
    return 0;
}