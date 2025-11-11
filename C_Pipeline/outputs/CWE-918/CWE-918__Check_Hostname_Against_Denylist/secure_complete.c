#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdint.h>
#include <math.h>
#include <limits.h>
#include <stdbool.h>

const char* DENIED_DOMAINS[] = {"localhost", "127.0.0.1", "admin.internal", NULL};

#include <string.h>
#include <ctype.h>

int is_hostname_in_list(const char* hostname, const char** denied_domains) {
    if (!hostname || !denied_domains) return 0;

    while (*denied_domains) {
        const char* domain = *denied_domains;
        if (domain) {
            size_t length = strlen(hostname);
            size_t domain_length = strlen(domain);
            if (length == domain_length) {
                int match = 1;
                for (size_t i = 0; i < length; i++) {
                    if (tolower((unsigned char)hostname[i]) != tolower((unsigned char)domain[i])) {
                        match = 0;
                        break;
                    }
                }
                if (match) return 1;
            }
        }
        denied_domains++;
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
    const char** denied_domains = DENIED_DOMAINS; // From setup


    // Execute function
    int result = is_hostname_in_list(hostname, denied_domains);

    printf("%ld\n", (long)result);
    return 0;
}