#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdint.h>
#include <math.h>
#include <limits.h>
#include <stdbool.h>

int is_url_valid_format(const char* url) {
    const char* scheme_end = strstr(url, "://");
    if (!scheme_end || scheme_end == url) {
        return 0;
    }
    const char* host_start = scheme_end + 3;
    const char* host_end = strchr(host_start, '/');
    if (host_end == host_start) {
        return 0;
    }
    for (const char* p = host_start; p != host_end && *p != '\0'; ++p) {
        if (((*p < '0' || *p > '9') && (*p < 'a' || *p > 'z') && (*p < 'A' || *p > 'Z') && *p != '.' && *p != '-')) {
            return 0;
        }
    }
  
    char buffer[256];
    if (strlen(url) < 256) {
        strcpy(buffer, url);
    } else {
        return 0;
    }

    if (strstr(buffer, "://")) {
        return 1;
    }
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


    // Execute function
    int result = is_url_valid_format(url);

    printf("%ld\n", (long)result);
    return 0;
}