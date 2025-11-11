#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <arpa/inet.h>

int is_ip_in_ranges(const char* ip_str, const char** reserved_ranges) {
    struct in_addr ip;
    
    if (inet_pton(AF_INET, ip_str, &ip) != 1) {
        return 0;
    }

    while (*reserved_ranges) {
        char range[18]; 
        strncpy(range, *reserved_ranges, sizeof(range) - 1);
        range[sizeof(range) - 1] = '\0';
        
        char* slash = strchr(range, '/');
        if (!slash) {
            reserved_ranges++;
            continue;
        }

        *slash = '\0';
        int cidr = atoi(slash + 1);

        struct in_addr net_ip, mask;
        if (inet_pton(AF_INET, range, &net_ip) != 1) {
            reserved_ranges++;
            continue;
        }

        mask.s_addr = htonl(~((1 << (32 - cidr)) - 1));
        if ((ip.s_addr & mask.s_addr) == (net_ip.s_addr & mask.s_addr)) {
            return 1;
        }
        
        reserved_ranges++;
    }
    
    return 0;
}