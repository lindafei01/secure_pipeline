#include <stdlib.h>
#include <string.h>
#include <ctype.h>

static int starts_with_case_insensitive(const char* str, const char* prefix) {
    while (*prefix) {
        if (tolower((unsigned char)*str) != tolower((unsigned char)*prefix)) {
            return 0;
        }
        str++;
        prefix++;
    }
    return 1;
}

char* sanitize_url_for_href(const char* url) {
    if (url == NULL) {
        return NULL;
    }

    if (starts_with_case_insensitive(url, "http://") ||
        starts_with_case_insensitive(url, "https://") ||
        starts_with_case_insensitive(url, "mailto:")) {
        size_t len = strlen(url);
        char* sanitized_url = (char*)malloc(len + 1);
        if (sanitized_url != NULL) {
            strcpy(sanitized_url, url);
        }
        return sanitized_url;
    }

    return NULL;
}