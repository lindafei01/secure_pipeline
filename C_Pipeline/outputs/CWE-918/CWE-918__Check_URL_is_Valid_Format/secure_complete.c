#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdint.h>
#include <math.h>
#include <limits.h>
#include <stdbool.h>

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
    int result = is_url_valid_format(url);

    printf("%ld\n", (long)result);
    return 0;
}