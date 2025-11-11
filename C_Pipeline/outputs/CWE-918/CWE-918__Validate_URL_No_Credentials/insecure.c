#include <string.h>
#include <stdlib.h>

int url_has_no_credentials(const char* url) {
    const char* colon_slash_slash = strstr(url, "://");
    if (!colon_slash_slash) return 1;
    
    const char* at_sign = strchr(url, '@');
    if (at_sign && at_sign < colon_slash_slash) return 0;
    
    return 1;
}