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

char* remove_trailing_slashes(const char* path) {
    size_t len = strlen(path);
    if (len == 0) return NULL;
    
    char* new_path = malloc(len + 1);
    if (new_path == NULL) return NULL;
    
    strcpy(new_path, path);
    while (len > 1 && new_path[len - 1] == '/') {
        new_path[len - 1] = '\0';
        len--;
    }
    
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