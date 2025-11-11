#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdint.h>
#include <math.h>
#include <limits.h>
#include <stdbool.h>

char* normalize_path(const char* path) {
    if (!path) return NULL;
    
    size_t len = strlen(path);
    char* normalized = (char*)malloc(len + 1);
    if (!normalized) return NULL;
    
    int depth = 0;
    size_t index = 0;
    
    for (size_t i = 0; i < len; ) {
        if (path[i] == '.' && (i + 1 == len || path[i + 1] == '/')) {
            i += 1 + (i + 1 < len);
        } else if (path[i] == '.' && path[i + 1] == '.' && (i + 2 == len || path[i + 2] == '/')) {
            i += 2 + (i + 2 < len);
            if (depth > 0) {
                while (index > 0 && normalized[index - 1] != '/') {
                    index--;
                }
                if (index > 0) index--;
                depth--;
            }
        } else {
            if (path[i] == '/') {
                normalized[index++] = path[i++];
            } else {
                size_t start = i;
                while (i < len && path[i] != '/') i++;
                memcpy(normalized + index, path + start, i - start);
                index += i - start;
                depth++;
            }
        }
    }
    
    if (depth < 0) {
        free(normalized);
        return NULL;
    }
    
    normalized[index] = '\0';
    return normalized;
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