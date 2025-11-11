#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdint.h>
#include <math.h>
#include <limits.h>
#include <stdbool.h>

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
// Auto-generated dynamic test driver (zero hard-code)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[])
{
    if (argc < 2) {
        printf("Usage: %s webhook_url\n", argv[0]);
        return 1;
    }
    // Auto-generated argument parsing (no hardcode)
    const char* webhook_url = argv[1];


    // Execute function
    int result = is_valid_webhook_url(webhook_url);

    printf("%ld\n", (long)result);
    return 0;
}