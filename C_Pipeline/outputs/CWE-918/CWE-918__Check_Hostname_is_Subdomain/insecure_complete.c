#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdint.h>
#include <math.h>
#include <limits.h>
#include <stdbool.h>

int is_subdomain(const char* hostname, const char* parent_domain) {
    if (hostname == NULL || parent_domain == NULL) return 0;
    
    int hostname_len = strlen(hostname);
    int parent_domain_len = strlen(parent_domain);
    
    if (hostname_len < parent_domain_len) return 0;

    const char* cmp_part = hostname + (hostname_len - parent_domain_len);

    if (strcasecmp(cmp_part, parent_domain) == 0) {
        if (hostname_len == parent_domain_len) {
            return 1;
        } else if (*(cmp_part - 1) == '.') {
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