#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdint.h>
#include <math.h>
#include <limits.h>
#include <stdbool.h>

#include <string.h>
#include <ctype.h>

int is_valid_webhook_url(const char* webhook_url) {
    if (!webhook_url) return 0;
    
    const char* https_prefix = "https://";
    size_t https_length = strlen(https_prefix);
    
    if (strncmp(webhook_url, https_prefix, https_length) != 0) {
        return 0;
    }
    
    const char* hostname_start = webhook_url + https_length;
    
    if (!*hostname_start) return 0;
    
    while (*hostname_start && *hostname_start != '/') {
        if ((*hostname_start >= '0' && *hostname_start <= '9') || *hostname_start == '.') {
            return 0;
        }
        hostname_start++;
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