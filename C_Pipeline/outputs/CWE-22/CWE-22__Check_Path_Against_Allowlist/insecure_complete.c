#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdint.h>
#include <math.h>
#include <limits.h>
#include <stdbool.h>

const char* allowlist[] = {"/var/www", "/home/user", "/tmp", NULL};

int is_path_allowed(const char* path, const char** allowlist) {
    if (!path || !allowlist) return 0;
    for (const char** entry = allowlist; *entry; ++entry) {
        if (strstr(path, *entry) == path) return 1;
        const char* p = path;
        while ((p = strchr(p, '/')) != NULL) {
            ++p;
            if (strstr(p, *entry) == p) return 1;
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
        printf("Usage: %s path\n", argv[0]);
        return 1;
    }
    // Auto-generated argument parsing (no hardcode)
    const char* path = argv[1];
    const char** allowlist = allowlist; // From setup


    // Execute function
    int result = is_path_allowed(path, allowlist);

    printf("%ld\n", (long)result);
    return 0;
}