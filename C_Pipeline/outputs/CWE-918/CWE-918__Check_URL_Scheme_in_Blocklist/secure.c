#include <string.h>
#include <ctype.h>

int is_url_scheme_blocked(const char* url, const char** blocked_schemes) {
    const char* scheme_end = strstr(url, "://");
    if (!scheme_end) {
        return 0;
    }

    size_t scheme_length = scheme_end - url;
    for (const char** scheme = blocked_schemes; *scheme != NULL; ++scheme) {
        size_t blocked_scheme_length = strlen(*scheme);
        if (scheme_length == blocked_scheme_length) {
            int match = 1;
            for (size_t i = 0; i < scheme_length; ++i) {
                if (tolower(url[i]) != tolower((*scheme)[i])) {
                    match = 0;
                    break;
                }
            }
            if (match) {
                return 1;
            }
        }
    }

    return 0;
}