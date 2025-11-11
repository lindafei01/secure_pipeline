int path_contains_dot_dot(const char* path) {
    if (path == NULL) {
        return 0;
    }
    const char* ptr = path;
    while (*ptr) {
        if (*ptr == '.' && *(ptr + 1) == '.') {
            return 1;
        }
        ptr++;
    }
    return 0;
}