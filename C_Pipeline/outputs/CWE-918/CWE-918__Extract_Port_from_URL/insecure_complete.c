#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdint.h>
#include <math.h>
#include <limits.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int get_url_port(const char* url) {
    char scheme[6] = {0};
    char host[256] = {0};
    int port = 0;

    if (sscanf(url, "%5[^:]://%255[^:/]:%d", scheme, host, &port) == 3) {
        return port;
    } else if (sscanf(url, "%5[^:]://%255[^:/]", scheme, host) == 2) {
        if (strcmp(scheme, "http") == 0) {
            return 80;
        } else if (strcmp(scheme, "https") == 0) {
            return 443;
        }
    }
    return -1;
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