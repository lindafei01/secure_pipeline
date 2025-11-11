#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdint.h>
#include <math.h>
#include <limits.h>
#include <stdbool.h>

const char* LOCALHOST_DEFS[] = {"localhost", "127.0.0.1", NULL};

#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int is_url_hostname_in_list(const char* url, const char** definitions) {
    if (url == NULL || definitions == NULL) {
        return 0;
    }

    const char* prefix_http = "http://";
    const char* prefix_https = "https://";
    const char* hostname_start = NULL;

    if (strncmp(url, prefix_http, 7) == 0) {
        hostname_start = url + 7;
    } else if (strncmp(url, prefix_https, 8) == 0) {
        hostname_start = url + 8;
    } else {
        return 0;
    }

    const char* hostname_end = strchr(hostname_start, '/');
    size_t hostname_length = (hostname_end == NULL) ? strlen(hostname_start) : (size_t)(hostname_end - hostname_start);

    char* host_lower = (char*)malloc(hostname_length + 1);
    if (host_lower == NULL) {
        return 0;
    }

    for (size_t i = 0; i < hostname_length; ++i) {
        host_lower[i] = tolower(hostname_start[i]);
    }
    host_lower[hostname_length] = '\0';

    int match_found = 0;
    for (int i = 0; definitions[i] != NULL; ++i) {
        size_t def_length = strlen(definitions[i]);
        if (def_length == hostname_length) {
            int match = 1;
            for (size_t j = 0; j < def_length; ++j) {
                if (tolower(definitions[i][j]) != host_lower[j]) {
                    match = 0;
                    break;
                }
            }
            if (match) {
                match_found = 1;
                break;
            }
        }
    }

    free(host_lower);
    return match_found;
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
    const char** definitions = LOCALHOST_DEFS; // From setup


    // Execute function
    int result = is_url_hostname_in_list(url, definitions);

    printf("%ld\n", (long)result);
    return 0;
}