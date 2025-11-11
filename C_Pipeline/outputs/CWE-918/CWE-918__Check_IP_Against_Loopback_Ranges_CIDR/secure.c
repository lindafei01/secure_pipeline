#include <arpa/inet.h>
#include <string.h>

int is_ip_in_ranges(const char* ip_str, const char** loopback_ranges) {
    struct in_addr ip_addr, range_addr, mask, network;
    unsigned int cidr;
    
    if (inet_pton(AF_INET, ip_str, &ip_addr) != 1) {
        return 0;
    }
    
    for (int i = 0; loopback_ranges[i] != NULL; i++) {
        const char* cidr_str = loopback_ranges[i];
        char* slash = strchr(cidr_str, '/');
        
        if (slash == NULL) {
            continue;
        }
        
        char ip_buffer[16];
        size_t prefix_len = slash - cidr_str;

        if (prefix_len >= sizeof(ip_buffer)) {
            continue;
        }

        memcpy(ip_buffer, cidr_str, prefix_len);
        ip_buffer[prefix_len] = '\0';
        
        if (sscanf(slash + 1, "%u", &cidr) != 1 || cidr > 32) {
            continue;
        }
        
        if (inet_pton(AF_INET, ip_buffer, &range_addr) != 1) {
            continue;
        }
        
        mask.s_addr = htonl((((unsigned int)1 << cidr) - 1) << (32 - cidr));
        network.s_addr = range_addr.s_addr & mask.s_addr;
        
        if ((ip_addr.s_addr & mask.s_addr) == network.s_addr) {
            return 1;
        }
    }
    
    return 0;
}