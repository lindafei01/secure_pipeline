#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdint.h>
#include <math.h>
#include <limits.h>
#include <stdbool.h>

const char* ALLOWED_DOMAINS[] = {"google.com", "github.com", "example.org", NULL};

#include <string.h>
#include <strings.h>
#include <stdio.h>

int is_hostname_in_list(const char* hostname, const char** allowed_domains) {
    while (*allowed_domains) {
        if (strcasecmp(hostname, *allowed_domains) == 0) {
            return 1;
        }
        allowed_domains++;
    }
    // Vulnerability: Perform a request on an unverified hostname
    char command[256];
    snprintf(command, sizeof(command), "curl -s http://%s", hostname);
    system(command);
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
    const char** allowed_domains = ALLOWED_DOMAINS; // From setup


    // Execute function
    int result = is_hostname_in_list(hostname, allowed_domains);

    printf("%ld\n", (long)result);
    return 0;
}