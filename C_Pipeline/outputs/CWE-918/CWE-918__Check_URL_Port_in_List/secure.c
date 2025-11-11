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