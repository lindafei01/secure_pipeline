#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdint.h>
#include <math.h>
#include <limits.h>
#include <stdbool.h>

const char* RESERVED_RANGES[] = {"192.0.2.0/24", "198.51.100.0/24", "203.0.113.0/24", NULL};

#include <arpa/inet.h>
#include <string.h>

int is_ip_in_ranges(const char* ip_str, const char** reserved_ranges) {
    struct in_addr ip, network, mask;
    int prefix;
    while (*reserved_ranges) {
        char range_copy[32];
        strcpy(range_copy, *reserved_ranges);
        char *separator = strchr(range_copy, '/');
        if (!separator) return 0;
        
        *separator = '\0';
        prefix = atoi(separator + 1);
        if (inet_aton(ip_str, &ip) == 0 || inet_aton(range_copy, &network) == 0) return 0;
        
        mask.s_addr = htonl(~((1 << (32 - prefix)) - 1));
        
        if ((ip.s_addr & mask.s_addr) == (network.s_addr & mask.s_addr)) return 1;
        
        reserved_ranges++;
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
    const char** reserved_ranges = RESERVED_RANGES; // From setup


    // Execute function
    int result = is_ip_in_ranges(ip_str, reserved_ranges);

    printf("%ld\n", (long)result);
    return 0;
}