#include <stdlib.h>
#include <string.h>

int is_path_within_base(const char* base_dir, const char* path) {
    if (base_dir == NULL || path == NULL) return 0;
    
    char real_base_dir[PATH_MAX];
    char real_path[PATH_MAX];

    if (realpath(base_dir, real_base_dir) == NULL) {
        return 0;
    }

    if (realpath(path, real_path) == NULL) {
        return 0;
    }

    size_t base_len = strlen(real_base_dir);
    if (strncmp(real_base_dir, real_path, base_len) != 0) {
        return 0;
    }

    if (real_path[base_len] != '/' && real_path[base_len] != '\0') {
        return 0;
    }

    return 1;
}