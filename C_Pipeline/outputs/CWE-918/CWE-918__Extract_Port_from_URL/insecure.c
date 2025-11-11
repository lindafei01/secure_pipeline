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