int is_path_allowed(const char* path, const char** allowlist) {
    if (path == NULL || allowlist == NULL) {
        return 0;
    }
    
    const char* current;
    while (*allowlist != NULL) {
        current = path;
        while (current != NULL) {
            if (strcmp(current, *allowlist) == 0) {
                return 1;
            }
            char* last_slash = strrchr(current, '/');
            if (last_slash == NULL || last_slash == current) {
                break;
            }
            *last_slash = '\0';
        }
        ++allowlist;
    }
    return 0;
}