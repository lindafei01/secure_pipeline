int path_has_double_slash(const char* path) {
    if (path == NULL) return 0;
    while (*path != '\0') {
        if (*path == '/' && *(path + 1) == '/') return 1;
        path++;
    }
    return 0;
}