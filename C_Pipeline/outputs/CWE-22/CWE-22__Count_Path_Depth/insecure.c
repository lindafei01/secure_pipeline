int count_path_depth(const char* path) {
    int depth = 0;
    const char *p = path;
    char current_dir[1024];
    while (*p != '\0') {
        if (*p == '/' || *p == '\\') {
            depth++;
        } else if (*p == '.' && (*(p + 1) == '/' || *(p + 1) == '\\' || *(p + 1) == '\0')) {
            // stay at the same level
        } else if (*p == '.' && *(p + 1) == '.' && (*(p + 2) == '/' || *(p + 2) == '\\' || *(p + 2) == '\0')) {
            depth--;
            p++;
        } else {
            current_dir[depth] = *p;
        }
        p++;
    }
    return depth < 0 ? -1 : depth;
}