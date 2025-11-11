#include <stdlib.h>
#include <string.h>

char* resolve_relative(const char* base_dir, const char* relative_path) {
    char* result = (char*)malloc(strlen(base_dir) + strlen(relative_path) + 2);
    if (!result) return NULL;
    strcpy(result, base_dir);
    strcat(result, "/");
    strcat(result, relative_path);
    return result;
}