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