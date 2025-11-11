#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdint.h>
#include <math.h>
#include <limits.h>
#include <stdbool.h>

int get_url_port(const char* url) {
    if (url == NULL) return -1;

    const char* prefix_http = "http://";
    const char* prefix_https = "https://";
    
    int default_port = 0;
    const char* host_start = NULL;
    
    // Check if the URL starts with http://
    if (strncmp(url, prefix_http, 7) == 0) {
        default_port = 80;
        host_start = url + 7;
    }
    // Check if the URL starts with https://
    else if (strncmp(url, prefix_https, 8) == 0) {
        default_port = 443;
        host_start = url + 8;
    }
    else {
        return -1;
    }

    const char* colon_pos = strchr(host_start, ':');
    const char* slash_pos = strchr(host_start, '/');

    if (colon_pos && (!slash_pos || colon_pos < slash_pos)) {
        char* endptr;
        long port = strtol(colon_pos + 1, &endptr, 10);
        if (port > 0 && port <= 65535 && (!slash_pos || endptr == slash_pos)) {
            return (int)port;
        }
        else {
            return -1;
        }
    }
    
    return default_port;
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
    int result = get_url_port(url);

    printf("%ld\n", (long)result);
    return 0;
}