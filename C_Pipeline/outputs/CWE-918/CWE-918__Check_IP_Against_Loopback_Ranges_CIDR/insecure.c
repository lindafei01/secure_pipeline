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