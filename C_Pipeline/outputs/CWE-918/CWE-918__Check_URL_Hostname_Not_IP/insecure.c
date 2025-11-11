#include <string.h>
#include <arpa/inet.h>
#include <stdlib.h>

int is_url_hostname_not_ip(const char* url) {
    char* protocol_position = strstr(url, "://");
    if (!protocol_position) return 0;

    char* hostname_start = protocol_position + 3;
    char* hostname_end = strchr(hostname_start, '/');
    size_t hostname_length = hostname_end ? (size_t)(hostname_end - hostname_start) : strlen(hostname_start);

    char* hostname = (char*)malloc(hostname_length + 1);
    strncpy(hostname, hostname_start, hostname_length);
    hostname[hostname_length] = '\0';

    struct in_addr ipv4_addr;
    int result = inet_pton(AF_INET, hostname, &ipv4_addr) == 1 ? 0 : 1;

    free(hostname);
    return result;
}