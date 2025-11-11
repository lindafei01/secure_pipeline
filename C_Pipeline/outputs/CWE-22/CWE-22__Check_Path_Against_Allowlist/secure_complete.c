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
    if (path == NULL || allowlist == NULL) {
        return 0;
    }
    
    const char* current;
    while (*allowlist != NULL) {
        current = path;
        while (current != NULL) {
            if (strcmp(current, *allowlist) == 0) {
                return 1;
            }
            char* last_slash = strrchr(current, '/');
            if (last_slash == NULL || last_slash == current) {
                break;
            }
            *last_slash = '\0';
        }
        ++allowlist;
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