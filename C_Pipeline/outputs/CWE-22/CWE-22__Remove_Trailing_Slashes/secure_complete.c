#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdint.h>
#include <math.h>
#include <limits.h>
#include <stdbool.h>

char* remove_trailing_slashes(const char* path) {
    if (path == NULL) {
        return NULL;
    }
    
    size_t len = strlen(path);
    if (len == 0) {
        return NULL;
    }

    size_t i = len - 1;
    while (i > 0 && path[i] == '/') {
        i--;
    }
    
    if (i == 0 && path[0] == '/') {
        i = 1; 
    }
  
    char* new_path = (char*)malloc((i + 1) + 1);
    if (new_path == NULL) {
        return NULL;
    }

    strncpy(new_path, path, i + 1);
    new_path[i + 1] = '\0';

    return new_path;
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
    char* result = remove_trailing_slashes(path);

    if (result == NULL) {
        printf("NULL\n");
    } else {
        printf("%s\n", result);
    }
    return 0;
}