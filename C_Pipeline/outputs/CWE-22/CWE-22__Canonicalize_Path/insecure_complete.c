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