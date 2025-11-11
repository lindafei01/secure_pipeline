#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdint.h>
#include <math.h>
#include <limits.h>
#include <stdbool.h>

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
// Auto-generated dynamic test driver (zero hard-code)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[])
{
    if (argc < 2) {
        printf("Usage: %s hostname\n", argv[0]);
        return 1;
    }
    // Auto-generated argument parsing (no hardcode)
    const char* hostname = argv[1];


    // Execute function
    int result = is_hostname_literal_ip(hostname);

    printf("%ld\n", (long)result);
    return 0;
}