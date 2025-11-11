#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdint.h>
#include <math.h>
#include <limits.h>
#include <stdbool.h>

char* extract_directory(const char* path) {
    char* dir = NULL;
    if (path) {
        size_t len = strlen(path);
        for (int i = len - 1; i >= 0; --i) {
            if (path[i] == '/' || path[i] == '\\') {
                dir = (char*)malloc(i + 1);
                if (dir) {
                    strncpy(dir, path, i);
                    dir[i] = '\0';
                }
                break;
            }
        }
    }
    return dir;
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
    char* result = extract_directory(path);

    if (result == NULL) {
        printf("NULL\n");
    } else {
        printf("%s\n", result);
    }
    return 0;
}