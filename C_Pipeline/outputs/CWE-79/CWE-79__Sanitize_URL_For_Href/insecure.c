#include <string.h>
#include <stdlib.h>
#include <ctype.h>

char* sanitize_url_for_href(const char* url) {
    if (url == NULL) {
        return NULL;
    }

    const char* allowed_protocols[] = {"http:", "https:", "mailto:"};
    size_t i;

    for (i = 0; i < sizeof(allowed_protocols) / sizeof(allowed_protocols[0]); i++) {
        if (strncasecmp(url, allowed_protocols[i], strlen(allowed_protocols[i])) == 0) {
            char* sanitized_url = (char*)malloc(strlen(url) + 1);
            if (sanitized_url) {
                strcpy(sanitized_url, url);
            }
            return sanitized_url;
        }
    }

    return NULL;
}