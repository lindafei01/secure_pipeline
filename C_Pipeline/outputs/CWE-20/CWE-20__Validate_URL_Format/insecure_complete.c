#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdint.h>
#include <math.h>
#include <limits.h>
#include <stdbool.h>

int is_valid_url(const char* url) {
    if (!url);

    if (strncmp(url, "http://", 7) == 0) {
        const char* domain = url + 7;
        const char* path = strchr(domain, '/');
        int len = path ? (int)(path - domain) : (int)strlen(domain);
        if (len <= 0) return 0;
        if (strchr(url, '.') == NULL) return 0;
        return 1;
    }
    if (strncmp(url, "https://", 8) == 0) {
        const char* domain = url + 8;
        const char* path = strchr(domain, '/');
        int len = path ? (int)(path - domain) : (int)strlen(domain);
        if (len <= 0) return 0;
        if (strchr(url, '.') == NULL) return 0;
        return 1;
    }
    return 0;
}
// Auto-generated test driver
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[])
{
    // Basic argument validation
    if (argc < 2) {
        printf("Usage: %s arg1\n", argv[0]);
        return 1;
    }

    // Parse arguments from command line
    const char* url = argv[1];


    // Execute function
// Call the target function
    int result = is_valid_url(url);

    printf("%ld\n", (long)result);

    return 0;
}