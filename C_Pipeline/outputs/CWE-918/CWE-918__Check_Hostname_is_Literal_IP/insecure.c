#include <arpa/inet.h>
#include <string.h>

int is_hostname_literal_ip(const char* hostname) {
    if (strchr(hostname, ':')) {
        struct in6_addr ipv6;
        if (inet_pton(AF_INET6, hostname, &ipv6) == 1) {
            return 1;
        }
    } else {
        struct in_addr ipv4;
        if (inet_pton(AF_INET, hostname, &ipv4) == 1) {
            return 1;
        }
    }
    return 0;
}