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
    if (!url || !allowed_schemes) return 0;
    
    const char* scheme_end = strstr(url, "://");
    if (!scheme_end) return 0;
    
    size_t scheme_len = scheme_end - url;
    if (scheme_len == 0) return 0;
    
    while (*allowed_schemes) {
        const char* allowed_scheme = *allowed_schemes;
        size_t allowed_len = strlen(allowed_scheme);
        
        if (allowed_len == scheme_len && strncasecmp(url, allowed_scheme, scheme_len) == 0) {
            return 1;
        }
        
        allowed_schemes++;
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