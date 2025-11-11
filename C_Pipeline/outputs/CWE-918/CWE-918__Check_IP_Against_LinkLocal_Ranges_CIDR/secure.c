#include <arpa/inet.h>
#include <string.h>

int ip_in_range(const char* ip_str, const char* cidr_str) {
    struct in_addr ip_addr, net_addr, mask;
    int prefix_len;

    if (inet_pton(AF_INET, ip_str, &ip_addr) != 1) {
        return 0;
    }

    char cidr[strlen(cidr_str) + 1];
    strcpy(cidr, cidr_str);

    char* slash = strchr(cidr, '/');
    if (slash == NULL) {
        return 0;
    }

    *slash = '\0';
    prefix_len = atoi(slash + 1);

    if (inet_pton(AF_INET, cidr, &net_addr) != 1) {
        return 0;
    }

    mask.s_addr = htonl(~((1 << (32 - prefix_len)) - 1));

    if ((ip_addr.s_addr & mask.s_addr) == (net_addr.s_addr & mask.s_addr)) {
        return 1;
    }

    return 0;
}

int is_ip_in_ranges(const char* ip_str, const char** link_local_ranges) {
    for (; *link_local_ranges != NULL; link_local_ranges++) {
        if (ip_in_range(ip_str, *link_local_ranges)) {
            return 1;
        }
    }
    return 0;
}