#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdint.h>
#include <math.h>
#include <limits.h>
#include <stdbool.h>

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