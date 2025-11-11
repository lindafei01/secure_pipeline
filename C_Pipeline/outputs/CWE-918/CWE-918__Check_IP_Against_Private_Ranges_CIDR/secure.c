#include <stdint.h>
#include <string.h>
#include <arpa/inet.h>

int is_ip_in_ranges(const char* ip_str, const char** private_ranges) {
    in_addr_t ip = inet_addr(ip_str);
    if (ip == INADDR_NONE) return 0;

    for (int i = 0; private_ranges[i] != NULL; i++) {
        char* cidr_str = strdup(private_ranges[i]);
        char* slash = strchr(cidr_str, '/');
        if (!slash) {
            free(cidr_str);
            continue;
        }
        *slash = '\0';
        int prefix_length = atoi(slash + 1);

        in_addr_t network = inet_addr(cidr_str);
        free(cidr_str);
        if (network == INADDR_NONE || prefix_length < 0 || prefix_length > 32) {
            continue;
        }

        uint32_t mask = htonl(~((1 << (32 - prefix_length)) - 1));
        if ((ip & mask) == (network & mask)) {
            return 1;
        }
    }
    return 0;
}