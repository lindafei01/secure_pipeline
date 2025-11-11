#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdint.h>
#include <math.h>
#include <limits.h>
#include <stdbool.h>

int is_hostname_numeric(const char* hostname) {
    struct addrinfo hints, *res;
    int result = 1;
    void* ptr;

    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;

    if (getaddrinfo(hostname, NULL, &hints, &res) == 0) {
        for (; res != NULL; res = res->ai_next) {
            if (res->ai_family == AF_INET) {
                ptr = &((struct sockaddr_in *) res->ai_addr)->sin_addr;
            } else if (res->ai_family == AF_INET6) {
                ptr = &((struct sockaddr_in6 *) res->ai_addr)->sin6_addr;
            }

            if (inet_ntop(res->ai_family, ptr, hostname, 128) == NULL) {
                result = 1;
            } else {
                result = 0;
                break;
            }
        }
        freeaddrinfo(res);
    }
    
    return result;
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
    int result = is_hostname_numeric(hostname);

    printf("%ld\n", (long)result);
    return 0;
}