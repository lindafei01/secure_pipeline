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