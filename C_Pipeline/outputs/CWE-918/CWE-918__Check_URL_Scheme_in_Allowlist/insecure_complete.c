#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdint.h>
#include <math.h>
#include <limits.h>
#include <stdbool.h>

const char* SCHEME_HTTP_HTTPS[] = {"http", "https", NULL};

int is_url_scheme_allowed(const char* url, const char** allowed_schemes) {
    const char *colon = strstr(url, "://");
    if (!colon) return 0;
    int scheme_length = colon - url;
    char scheme[scheme_length + 1];
    memcpy(scheme, url, scheme_length);
    scheme[scheme_length] = '\0';

    for (int i = 0; allowed_schemes[i] != NULL; i++) {
        if (strcasecmp(scheme, allowed_schemes[i]) == 0) return 1;
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
    const char** allowed_schemes = SCHEME_HTTP_HTTPS; // From setup


    // Execute function
    int result = is_url_scheme_allowed(url, allowed_schemes);

    printf("%ld\n", (long)result);
    return 0;
}