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

char* normalize_path(const char* path) {
    size_t len = strlen(path);
    if (len == 0) return NULL;

    char* buffer = (char*)malloc(len + 1);
    if (!buffer) return NULL;

    size_t buffer_index = 0;
    size_t path_index = 0;

    int traversal_count = 0;

    while (path_index < len) {
        if (path[path_index] == '/') {
            path_index++;
        } else if (strncmp(&path[path_index], "..", 2) == 0 && 
                  (path_index + 2 == len || path[path_index + 2] == '/')) {
            if (buffer_index > 0) {
                while (buffer_index > 0 && buffer[buffer_index - 1] != '/') {
                    buffer_index--;
                }
                if (buffer_index > 0) buffer_index--;
            } else {
                traversal_count++;
            }
            path_index += 2;
        } else if (strncmp(&path[path_index], ".", 1) == 0 && 
                  (path_index + 1 == len || path[path_index + 1] == '/')) {
            path_index += 1;
        } else {
            if (buffer_index != 0 && buffer[buffer_index - 1] != '/') {
                buffer[buffer_index++] = '/';
            }

            while (path_index < len && path[path_index] != '/') {
                buffer[buffer_index++] = path[path_index++];
            }
        }
    }

    buffer[buffer_index] = '\0';

    if (traversal_count > 0) {
        free(buffer);
        return NULL;
    }

    char* result = (char*)malloc(buffer_index + 1);
    if (!result) {
        free(buffer);
        return NULL;
    }

    strncpy(result, buffer, buffer_index + 1);
    free(buffer);
    return result;
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
    char* result = normalize_path(path);

    if (result == NULL) {
        printf("NULL\n");
    } else {
        printf("%s\n", result);
    }
    return 0;
}