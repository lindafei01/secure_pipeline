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

char* extract_filename(const char* path) {
    if (path == NULL) {
        return NULL;
    }
    
    size_t len = strlen(path);
    if (len == 0 || (len == 1 && path[0] == '/')) {
        return NULL;
    }

    const char* end = path + len - 1;
    while (end > path && *end == '/') {
        end--;
    }

    if (end == path && *end == '/') {
        return NULL;
    }

    const char* start = end;
    while (start > path && *(start - 1) != '/') {
        start--;
    }

    size_t filename_len = end - start + 1;
    char* filename = (char*)malloc(filename_len + 1);
    if (filename == NULL) {
        return NULL;
    }

    memcpy(filename, start, filename_len);
    filename[filename_len] = '\0';

    return filename;
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