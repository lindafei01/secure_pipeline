#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdint.h>
#include <math.h>
#include <limits.h>
#include <stdbool.h>

#include <stdlib.h>
#include <string.h>

char* canonicalize_path(const char* path) {
    if (path == NULL || path[0] != '/') return NULL;
    
    size_t len = strlen(path);
    if (len == 0) return NULL;

    char* resolved = (char*)malloc(len + 1);
    if (resolved == NULL) return NULL;

    const char *curr = path;
    char *res_ptr = resolved;
    
    while (*curr != '\0') {
        if (strncmp(curr, "/.", 2) == 0 && (curr[2] == '/' || curr[2] == '\0')) {
            curr += 2;
        } else if (strncmp(curr, "/..", 3) == 0 && (curr[3] == '/' || curr[3] == '\0')) {
            curr += 3;
            if (res_ptr > resolved) {
                res_ptr--;
                while (res_ptr > resolved && *res_ptr != '/') {
                    res_ptr--;
                }
            }
        } else {
            *res_ptr++ = *curr++;
        }
    }

    if (res_ptr == resolved) *res_ptr++ = '/';
    *res_ptr = '\0';

    return resolved;
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


    // Execute function
    char* result = canonicalize_path(path);

    if (result == NULL) {
        printf("NULL\n");
    } else {
        printf("%s\n", result);
    }
    return 0;
}