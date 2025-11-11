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