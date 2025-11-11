#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdint.h>
#include <math.h>
#include <limits.h>
#include <stdbool.h>

const char* PRIVATE_IP_RANGES[] = {"10.0.0.0/8", "172.16.0.0/12", "192.168.0.0/16", NULL};

#include <arpa/inet.h>
#include <string.h>

int is_ip_in_ranges(const char* ip_str, const char** private_ranges) {
    struct in_addr ip_addr;
    inet_pton(AF_INET, ip_str, &ip_addr);

    while (*private_ranges) {
        char *range = strdup(*private_ranges);
        char *sep = strchr(range, '/');
        if (sep) {
            *sep = '\0';
            int prefix_length = atoi(sep + 1);

            struct in_addr range_addr;
            inet_pton(AF_INET, range, &range_addr);
            
            unsigned long ip_binary = ntohl(ip_addr.s_addr);
            unsigned long range_binary = ntohl(range_addr.s_addr);
            unsigned long mask = (prefix_length == 0) ? 0 : ~((1 << (32 - prefix_length)) - 1);

            if ((ip_binary & mask) == (range_binary & mask)) {
                free(range);
                return 1;
            }
        }
        private_ranges++;
        free(range);
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
    const char** private_ranges = PRIVATE_IP_RANGES; // From setup


    // Execute function
    int result = is_ip_in_ranges(ip_str, private_ranges);

    printf("%ld\n", (long)result);
    return 0;
}