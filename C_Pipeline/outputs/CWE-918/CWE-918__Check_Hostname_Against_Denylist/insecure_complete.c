#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdint.h>
#include <math.h>
#include <limits.h>
#include <stdbool.h>

const char* DENIED_DOMAINS[] = {"localhost", "127.0.0.1", "admin.internal", NULL};

int is_hostname_in_list(const char* hostname, const char** denied_domains) {
    for (int i = 0; denied_domains[i] != NULL; i++) {
        if (strcasecmp(hostname, denied_domains[i]) == 0) {
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
    const char** denied_domains = DENIED_DOMAINS; // From setup


    // Execute function
    int result = is_hostname_in_list(hostname, denied_domains);

    printf("%ld\n", (long)result);
    return 0;
}