int path_starts_with(const char* path, const char* prefix) {
    if (!path || !prefix) return 0;

    while (*path && *prefix) {
        if (*path != *prefix) {
            return 0;
        }
        path++;
        prefix++;
    }

    if (*prefix == '\0') {
        if (*path == '/' || *path == '\0') {
            return 1;
        }
    }
    
    return 0;
}