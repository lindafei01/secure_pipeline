#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdint.h>
#include <math.h>
#include <limits.h>
#include <stdbool.h>

int is_ip_broadcast(const char* ip_str) {
    if (!ip_str) return 0;
    
    const char* expected = "255.255.255.255";
    
    while (*ip_str && *expected) {
        if (*ip_str != *expected) return 0;
        ip_str++;
        expected++;
    }
    
    return *ip_str == '\0' && *expected == '\0';
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
    int result = is_ip_broadcast(ip_str);

    printf("%ld\n", (long)result);
    return 0;
}