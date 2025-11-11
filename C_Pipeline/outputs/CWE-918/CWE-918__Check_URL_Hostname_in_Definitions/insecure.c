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