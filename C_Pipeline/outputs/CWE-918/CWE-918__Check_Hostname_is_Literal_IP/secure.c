#include <string.h>
#include <arpa/inet.h>

int is_hostname_literal_ip(const char* hostname) {
    struct sockaddr_in sa;
    struct sockaddr_in6 sa6;

    if (strchr(hostname, ':')) {
        if (hostname[0] == '[' && hostname[strlen(hostname) - 1] == ']') {
            char ipv6addr[INET6_ADDRSTRLEN];
            strncpy(ipv6addr, hostname + 1, strlen(hostname) - 2);
            ipv6addr[strlen(hostname) - 2] = '\0';
            if (inet_pton(AF_INET6, ipv6addr, &(sa6.sin6_addr))) {
                return 1;
            }
        }
    } else if (inet_pton(AF_INET, hostname, &(sa.sin_addr))) {
        return 1;
    }
    
    return 0;
}