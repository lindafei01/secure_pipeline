#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <arpa/inet.h>

int is_url_port_allowed(const char* url, const int* allowed_ports) {
    char url_copy[2048];
    char *scheme, *host, *port_str;
    int port = 0;

    strncpy(url_copy, url, 2047);
    url_copy[2047] = '\0';

    if ((scheme = strstr(url_copy, "://")) == NULL) return 0;

    *scheme = '\0';
    scheme += 3;

    if ((host = strstr(scheme, ":")) != NULL) {
        *host = '\0';
        host++;
        port_str = host;

        while (*port_str && isdigit(*port_str)) {
            port = port * 10 + (*port_str - '0');
            port_str++;
        }
    } else {
        host = scheme;
        if (strncmp(url_copy, "http", 4) == 0) port = 80;
        else if (strncmp(url_copy, "https", 5) == 0) port = 443;
    }
    
    if (*scheme) {
        struct sockaddr_in sa;
        if (inet_pton(AF_INET, scheme, &(sa.sin_addr))) {
            return 0;
        }
    }

    for (int i = 0; allowed_ports[i] != 0; i++) {
        if (allowed_ports[i] == port) return 1;
    }
    
    return 0;
}