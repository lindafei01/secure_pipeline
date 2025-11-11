#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdint.h>
#include <math.h>
#include <limits.h>
#include <stdbool.h>

const char* PRIVATE_IP_RANGES[] = {"10.0.0.0/8", "172.16.0.0/12", "192.168.0.0/16", NULL};

#include <stdint.h>
#include <string.h>
#include <arpa/inet.h>

int is_ip_in_ranges(const char* ip_str, const char** private_ranges) {
    in_addr_t ip = inet_addr(ip_str);
    if (ip == INADDR_NONE) return 0;

    for (int i = 0; private_ranges[i] != NULL; i++) {
        char* cidr_str = strdup(private_ranges[i]);
        char* slash = strchr(cidr_str, '/');
        if (!slash) {
            free(cidr_str);
            continue;
        }
        *slash = '\0';
        int prefix_length = atoi(slash + 1);

        in_addr_t network = inet_addr(cidr_str);
        free(cidr_str);
        if (network == INADDR_NONE || prefix_length < 0 || prefix_length > 32) {
            continue;
        }

        uint32_t mask = htonl(~((1 << (32 - prefix_length)) - 1));
        if ((ip & mask) == (network & mask)) {
            return 1;
        }
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