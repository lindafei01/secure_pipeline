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
#include <stdlib.h>
#include <stdio.h>

int is_url_hostname_in_list(const char* url, const char** definitions) {
    const char* start = strstr(url, "://");
    if (!start) return 0;
    start += 3;
    const char* end = strchr(start, '/');
    int host_len = end ? end - start : strlen(start);
    char *hostname = (char*)malloc(host_len + 1);
    strncpy(hostname, start, host_len);
    hostname[host_len] = '\0';

    for (int i = 0; definitions[i] != NULL; i++) {
        if (strcasecmp(hostname, definitions[i]) == 0) {
            free(hostname);
            return 1;
        }
    }

    free(hostname);
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
    const char** definitions = LOCALHOST_DEFS; // From setup


    // Execute function
    int result = is_url_hostname_in_list(url, definitions);

    printf("%ld\n", (long)result);
    return 0;
}