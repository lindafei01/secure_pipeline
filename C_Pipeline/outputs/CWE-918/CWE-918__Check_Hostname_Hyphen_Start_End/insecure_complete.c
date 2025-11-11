#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdint.h>
#include <math.h>
#include <limits.h>
#include <stdbool.h>

int hostname_has_hyphen_start_end(const char* hostname) {
    struct addrinfo hints, *res;
    int result;

    memset(&hints, 0, sizeof(hints));
    hints.ai_socktype = SOCK_STREAM;

    // This resolves the hostname which is vulnerable to SSRF (Server-Side Request Forgery)
    if ((result = getaddrinfo(hostname, NULL, &hints, &res)) != 0) {
        return 1; // invalid due to resolution failure
    }
    
    freeaddrinfo(res);

    // Check each label in the hostname
    const char* label = strtok((char*)hostname, ".");
    while (label != NULL) {
        if (label[0] == '-' || label[strlen(label) - 1] == '-') {
            return 1;
        }
        label = strtok(NULL, ".");
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
    int result = hostname_has_hyphen_start_end(hostname);

    printf("%ld\n", (long)result);
    return 0;
}