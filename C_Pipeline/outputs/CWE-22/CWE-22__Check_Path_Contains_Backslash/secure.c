int path_contains_backslash(const char* path) {
    if (path == NULL) {
        return 0;
    }
    while (*path) {
        if (*path == '\\') {
            return 1;
        }
        path++;
    }
    return 0;
}