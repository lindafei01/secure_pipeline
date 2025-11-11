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