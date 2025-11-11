#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdint.h>
#include <math.h>
#include <limits.h>
#include <stdbool.h>

const int ALLOWED_PORTS[] = {80, 443, 8080, 0};
const int STANDARD_PORTS[] = {80, 443, 0};

#include <string.h>
#include <stdlib.h>

int is_url_port_allowed(const char* url, const int* allowed_ports) {
    const char* http_prefix = "http://";
    const char* https_prefix = "https://";
    int default_port = 80;
    const char* colon;
    int port = -1;

    if (strncmp(url, http_prefix, strlen(http_prefix)) == 0) {
        url += strlen(http_prefix);
    } else if (strncmp(url, https_prefix, strlen(https_prefix)) == 0) {
        url += strlen(https_prefix);
        default_port = 443;
    }

    colon = strchr(url, ':');

    if (colon) {
        char* slash = strchr(colon, '/');
        if (slash) {
            char port_str[6];
            int len = slash - colon - 1;
            if (len > 5) return 0;
            strncpy(port_str, colon + 1, len);
            port_str[len] = '\0';
            port = atoi(port_str);
        } else {
            port = atoi(colon + 1);
        }
    } else {
        port = default_port;
    }

    while (*allowed_ports != 0) {
        if (*allowed_ports == port) {
            return 1;
        }
        allowed_ports++;
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
    const int* allowed_ports = ALLOWED_PORTS; // From setup


    // Execute function
    int result = is_url_port_allowed(url, allowed_ports);

    printf("%ld\n", (long)result);
    return 0;
}