#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdint.h>
#include <math.h>
#include <limits.h>
#include <stdbool.h>

#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <arpa/inet.h>
#include <stdio.h>

int is_valid_hostname(const char *hostname) {
    const int MAX_LABEL_LENGTH = 63;
    const int MAX_DOMAIN_LENGTH = 253;
    
    int length = strlen(hostname);
    if (length > MAX_DOMAIN_LENGTH || length == 0) return 0;
    
    if (hostname[0] == '-' || hostname[length - 1] == '-' ||
        hostname[0] == '.' || hostname[length - 1] == '.') {
        return 0;
    }

    int label_length = 0;
    for (int i = 0; i < length; i++) {
        if (hostname[i] == '.') {
            if (label_length == 0 || label_length > MAX_LABEL_LENGTH) return 0;
            label_length = 0;
        } else {
            if (!isalnum(hostname[i]) && hostname[i] != '-') {
                return 0;
            }
            label_length++;
        }
    }

    if (label_length == 0 || label_length > MAX_LABEL_LENGTH) return 0;

    for (int i = 0; i < length; i++) {
        if (hostname[i] == '.' && hostname[i + 1] == '.') {
            return 0;
        }
    }

    return 1;
}

int is_url_hostname_not_ip(const char* url) {
    if (!url || strstr(url, "://") == NULL) return 0;

    const char *hostname_start = strstr(url, "://") + 3;
    if (!hostname_start) return 0;

    const char *hostname_end = strstr(hostname_start, "/");
    if (!hostname_end) hostname_end = hostname_start + strlen(hostname_start);

    int hostname_length = hostname_end - hostname_start;
    char *hostname = (char *) malloc(hostname_length + 1);
    if (!hostname) return 0;

    strncpy(hostname, hostname_start, hostname_length);
    hostname[hostname_length] = '\0';

    struct in_addr addr;
    int is_ip = inet_pton(AF_INET, hostname, &addr);
    int result = 0;
    if (!is_ip && is_valid_hostname(hostname)) {
        result = 1;
    }

    free(hostname);
    return result;
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
    int result = is_url_hostname_not_ip(url);

    printf("%ld\n", (long)result);
    return 0;
}