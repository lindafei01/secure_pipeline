#include <string.h>
#include <arpa/inet.h>

int is_valid_webhook_url(const char* webhook_url) {
    if (strncmp(webhook_url, "https://", 8) != 0) {
        return 0;
    }

    const char* host_start = webhook_url + 8;
    
    struct sockaddr_in sa;
    if (inet_pton(AF_INET, host_start, &(sa.sin_addr)) == 1) {
        return 0;
    }

    return 1;
}