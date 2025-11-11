#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdint.h>
#include <math.h>
#include <limits.h>
#include <stdbool.h>

#include <string.h>
#include <strings.h>

int is_subdomain(const char* hostname, const char* parent_domain) {
    size_t hostname_len = strlen(hostname);
    size_t parent_domain_len = strlen(parent_domain);

    if (hostname_len < parent_domain_len) {
        return 0;
    }

    if (strcasecmp(hostname + hostname_len - parent_domain_len, parent_domain) == 0) {
        if (hostname_len == parent_domain_len) {
            return 1;
        }
        if (hostname[hostname_len - parent_domain_len - 1] == '.') {
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
    if (argc < 3) {
        printf("Usage: %s hostname parent_domain\n", argv[0]);
        return 1;
    }
    // Auto-generated argument parsing (no hardcode)
    const char* hostname = argv[1];
    const char* parent_domain = argv[2];


    // Execute function
    int result = is_subdomain(hostname, parent_domain);

    printf("%ld\n", (long)result);
    return 0;
}