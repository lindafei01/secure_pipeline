#include <stdlib.h>
#include <string.h>

char* canonicalize_path(const char* path) {
    if (path == NULL) return NULL;
    char* resolved_path = (char*) malloc(strlen(path) + 1);
    if (resolved_path == NULL) return NULL;
    strcpy(resolved_path, path);

    char* p = resolved_path;
    char* output = resolved_path;
    
    while (*p != '\0') {
        if (strncmp(p, "/..", 3) == 0 && (p[3] == '/' || p[3] == '\0')) {
            while (output > resolved_path && *(output - 1) != '/') output--;
            if (output > resolved_path) output--;
            p += 3;
        } else if (strncmp(p, "/.", 2) == 0 && (p[2] == '/' || p[2] == '\0')) {
            p += 2;
        } else if (*p == '/') {
            while (*(p + 1) == '/') p++;
            *(output++) = *(p++);
        } else {
            *(output++) = *(p++);
        }
    }
    *output = '\0';

    return resolved_path;
}