#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdint.h>
#include <math.h>
#include <limits.h>
#include <stdbool.h>

int is_ip_unspecified(const char* ip_str) {
    if (!ip_str) return 0;
    if (ip_str[0] == '0' && ip_str[1] == '.' && ip_str[2] == '0' && 
        ip_str[3] == '.' && ip_str[4] == '0' && ip_str[5] == '.' &&
        ip_str[6] == '0' && ip_str[7] == '\0') {
        return 1;
    }
    return 0;
}
// Auto-generated dynamic test driver (zero hard-code)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[])
{
    if (argc < 2) {
        printf("Usage: %s ip_str\n", argv[0]);
        return 1;
    }
    // Auto-generated argument parsing (no hardcode)
    const char* ip_str = argv[1];


    // Execute function
    int result = is_ip_unspecified(ip_str);

    printf("%ld\n", (long)result);
    return 0;
}