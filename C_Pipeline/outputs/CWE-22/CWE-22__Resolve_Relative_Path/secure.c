#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* resolve_relative(const char* base_dir, const char* relative_path) {
    if (!base_dir || !relative_path) return NULL;
    
    if (strstr(relative_path, "..")) return NULL;
    
    size_t base_len = strlen(base_dir);
    size_t rel_len = strlen(relative_path);
    
    int needs_slash = base_dir[base_len - 1] != '/';
    
    size_t total_len = base_len + rel_len + (needs_slash ? 1 : 0) + 1;
    
    char* abs_path = (char*)malloc(total_len);
    if (!abs_path) return NULL;
    
    snprintf(abs_path, total_len, "%s%s%s", base_dir, needs_slash ? "/" : "", relative_path);
    
    return abs_path;
}