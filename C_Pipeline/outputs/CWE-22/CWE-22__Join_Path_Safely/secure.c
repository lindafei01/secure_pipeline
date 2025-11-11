#include <stdlib.h>
#include <string.h>
#include <limits.h>

char* join_path_safe(const char* base_dir, const char* filename) {
    if (!base_dir || !filename) return NULL;
    
    char resolved_base[PATH_MAX];
    char resolved_file[PATH_MAX];
    
    if (!realpath(base_dir, resolved_base)) return NULL;
    
    if (strstr(filename, "..")) return NULL;
    
    snprintf(resolved_file, PATH_MAX, "%s/%s", resolved_base, filename);
    
    char resolved_result[PATH_MAX];
    if (!realpath(resolved_file, resolved_result)) return NULL;
    
    if (strncmp(resolved_base, resolved_result, strlen(resolved_base)) != 0) return NULL;
    
    return strdup(resolved_result);
}