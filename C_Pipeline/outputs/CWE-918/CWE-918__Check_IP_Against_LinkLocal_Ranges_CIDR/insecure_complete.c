#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdint.h>
#include <math.h>
#include <limits.h>
#include <stdbool.h>

const char* LINK_LOCAL_RANGES[] = {"169.254.0.0/16", NULL};

#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>

int is_ip_in_ranges(const char* ip_str, const char** link_local_ranges) {
    struct in_addr ip_addr;
    if (inet_pton(AF_INET, ip_str, &ip_addr) != 1) {
        return 0;
    }

    int in_range = 0;
    for (int i = 0; link_local_ranges[i] != NULL; ++i) {
        char cidr[256];
        strncpy(cidr, link_local_ranges[i], 255);

        char* slash_pos = strchr(cidr, '/');
        if (slash_pos == NULL) {
            continue;
        }

        *slash_pos = '\0';
        int prefix_len = atoi(slash_pos + 1);

        struct in_addr range_addr, mask_addr;
        if (inet_pton(AF_INET, cidr, &range_addr) != 1) {
            continue;
        }

        mask_addr.s_addr = htonl(~((1 << (32 - prefix_len)) - 1));

        if ((ip_addr.s_addr & mask_addr.s_addr) == (range_addr.s_addr & mask_addr.s_addr)) {
            in_range = 1;
            break;
        }
    }
    return in_range;
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
    const char** link_local_ranges = LINK_LOCAL_RANGES; // From setup


    // Execute function
    int result = is_ip_in_ranges(ip_str, link_local_ranges);

    printf("%ld\n", (long)result);
    return 0;
}