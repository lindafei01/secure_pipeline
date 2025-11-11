#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdint.h>
#include <math.h>
#include <limits.h>
#include <stdbool.h>

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


    // Execute function
    char* result = sanitize_url_for_href(url);

    if (result == NULL) {
        printf("NULL\n");
    } else {
        printf("%s\n", result);
    }
    return 0;
}