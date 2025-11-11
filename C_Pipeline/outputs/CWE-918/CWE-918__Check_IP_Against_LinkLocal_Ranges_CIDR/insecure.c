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