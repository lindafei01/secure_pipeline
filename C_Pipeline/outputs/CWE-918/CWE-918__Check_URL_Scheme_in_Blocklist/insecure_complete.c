#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdint.h>
#include <math.h>
#include <limits.h>
#include <stdbool.h>

const char* DANGEROUS_SCHEMES[] = {"file", "ftp", "gopher", "ldap", NULL};

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int is_url_scheme_blocked(const char* url, const char** blocked_schemes) {
    const char* scheme_end = strstr(url, "://");
    if (!scheme_end) return 0;

    int scheme_len = scheme_end - url;
    char scheme[scheme_len + 1];
    for (int i = 0; i < scheme_len; i++) {
        scheme[i] = tolower(url[i]);
    }
    scheme[scheme_len] = '\0';

    for (int i = 0; blocked_schemes[i] != NULL; i++) {
        if (strcasecmp(scheme, blocked_schemes[i]) == 0) {
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
        printf("Usage: %s url\n", argv[0]);
        return 1;
    }
    // Auto-generated argument parsing (no hardcode)
    const char* url = argv[1];
    const char** blocked_schemes = DANGEROUS_SCHEMES; // From setup


    // Execute function
    int result = is_url_scheme_blocked(url, blocked_schemes);

    printf("%ld\n", (long)result);
    return 0;
}