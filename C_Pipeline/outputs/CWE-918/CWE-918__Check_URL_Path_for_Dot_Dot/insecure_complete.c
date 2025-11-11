#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdint.h>
#include <math.h>
#include <limits.h>
#include <stdbool.h>

#include <string.h>

int url_path_has_dot_dot(const char* url) {
    const char* search = strstr(url, "://");
    if (search) {
        search += 3;
        search = strchr(search, '/');
    }
    else {
        search = strchr(url, '/');
    }

    if (search) {
        if (strstr(search, "..")) {
            return 1;
        }
    }
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
    int result = url_path_has_dot_dot(url);

    printf("%ld\n", (long)result);
    return 0;
}