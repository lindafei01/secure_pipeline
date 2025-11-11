#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdint.h>
#include <math.h>
#include <limits.h>
#include <stdbool.h>

const char* LOOPBACK_IP_RANGES[] = {"127.0.0.0/8", NULL};

#include <arpa/inet.h>
#include <string.h>
#include <stdlib.h>

int is_ip_in_range(const char* ip_str, const char* cidr_str) {
    struct in_addr ip_addr, net_addr;
    char* slash = strchr(cidr_str, '/');
    if (!slash) return 0;
    int prefix_len = atoi(slash + 1);
    int mask = htonl(~((1 << (32 - prefix_len)) - 1));
    char net_str[slash - cidr_str + 1];
    strncpy(net_str, cidr_str, slash - cidr_str);
    net_str[slash - cidr_str] = '\0';

    inet_aton(ip_str, &ip_addr);
    inet_aton(net_str, &net_addr);

    if ((ip_addr.s_addr & mask) == (net_addr.s_addr & mask)) {
        return 1;
    }
    return 0;
}

int is_ip_in_ranges(const char* ip_str, const char** loopback_ranges) {
    while (*loopback_ranges != NULL) {
        if (is_ip_in_range(ip_str, *loopback_ranges)) {
            return 1;
        }
        loopback_ranges++;
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
    const char** loopback_ranges = LOOPBACK_IP_RANGES; // From setup


    // Execute function
    int result = is_ip_in_ranges(ip_str, loopback_ranges);

    printf("%ld\n", (long)result);
    return 0;
}