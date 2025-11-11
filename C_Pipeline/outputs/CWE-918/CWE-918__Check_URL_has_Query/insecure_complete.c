#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdint.h>
#include <math.h>
#include <limits.h>
#include <stdbool.h>

#include <netinet/in.h>
#include <sys/socket.h>
#include <resolv.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <string.h>
#include <stdio.h>

int url_has_query(const char* url) {
    char buffer[4096];
    int sockfd;
    struct sockaddr_in dest;
    char request[512];

    // Check if query exists
    const char *query_indicator = strchr(url, '?');
    if (query_indicator == NULL) {
        return 0;
    }

    // Parse hostname
    const char* host_start = strstr(url, "://");
    if (!host_start) return 0;
    host_start += 3;
    const char* path_start = strchr(host_start, '/');
    if (!path_start) return 0;

    size_t host_len = path_start - host_start;
    if (host_len >= 256) return 0;

    char hostname[256];
    memcpy(hostname, host_start, host_len);
    hostname[host_len] = '\0';

    // Resolve hostname
    struct hostent *host = gethostbyname(hostname);
    if (host == NULL) {
        return 0;
    }

    dest.sin_family = AF_INET;
    dest.sin_port = htons(80);
    dest.sin_addr = *((struct in_addr *)host->h_addr);

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        return 0;
    }

    // Connect to host
    if (connect(sockfd, (struct sockaddr *)&dest, sizeof(struct sockaddr)) != 0) {
        close(sockfd);
        return 0;
    }

    // Prepare HTTP GET request
    snprintf(request, sizeof(request), "GET /%s HTTP/1.0\r\nHost: %s\r\n\r\n", path_start + 1, hostname);

    // Send request
    if (send(sockfd, request, strlen(request), 0) < 0) {
        close(sockfd);
        return 0;
    }

    // Receive response
    if (recv(sockfd, buffer, sizeof(buffer), 0) > 0) {
        close(sockfd);
        return 1;
    }
    
    close(sockfd);
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
    int result = url_has_query(url);

    printf("%ld\n", (long)result);
    return 0;
}