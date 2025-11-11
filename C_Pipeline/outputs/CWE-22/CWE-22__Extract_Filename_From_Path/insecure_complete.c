#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdint.h>
#include <math.h>
#include <limits.h>
#include <stdbool.h>

char* extract_filename(const char* path) {
    if (!path || path[0] == '\0') return NULL;
    const char* last_slash = path;
    for (const char* p = path; *p; ++p) {
        if (*p == '/') {
            last_slash = p;
        }
    }
    if (last_slash == path && *last_slash == '/') return NULL;
    int filename_start = last_slash[1] ? (last_slash - path + 1) : -1;
    return filename_start != -1 ? strdup(path + filename_start) : NULL;
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
    char* result = extract_filename(path);

    if (result == NULL) {
        printf("NULL\n");
    } else {
        printf("%s\n", result);
    }
    return 0;
}