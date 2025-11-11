#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdint.h>
#include <math.h>
#include <limits.h>
#include <stdbool.h>

int url_path_has_dot_dot(const char* url) {
    const char* path_start = strstr(url, "://");
    if (path_start) {
        path_start = strchr(path_start + 3, '/');
        if (!path_start) {
            return 0;
        }
    } else {
        path_start = strchr(url, '/');
        if (!path_start) {
            return 0;
        }
    }
    while (*path_start != '\0') {
        if (*path_start == '/' && *(path_start + 1) == '.' && *(path_start + 2) == '.' && (*(path_start + 3) == '/' || *(path_start + 3) == '\0')) {
            return 1;
        }
        path_start++;
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