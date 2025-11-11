#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdint.h>
#include <math.h>
#include <limits.h>
#include <stdbool.h>

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