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