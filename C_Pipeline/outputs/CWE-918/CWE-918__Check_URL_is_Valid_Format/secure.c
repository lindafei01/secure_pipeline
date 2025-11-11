#include <string.h>

int is_url_valid_format(const char* url) {
    if (url == NULL) {
        return 0;
    }
    
    const char* scheme_end = strstr(url, "://");
    if (scheme_end == NULL || scheme_end == url) {
        return 0;
    }
    
    const char* host_start = scheme_end + 3;
    if (*host_start == '\0') {
        return 0;
    }
    
    return 1;
}