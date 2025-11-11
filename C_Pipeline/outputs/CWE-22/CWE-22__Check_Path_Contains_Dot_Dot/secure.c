int path_contains_dot_dot(const char* path) {
    if (!path) return 0;
    const char* ptr = path;
    while (*ptr && *(ptr + 1) && *(ptr + 2)) {
        if (*ptr == '.' && *(ptr + 1) == '.' && (*(ptr + 2) == '/' || *(ptr + 2) == '\\' || *(ptr + 2) == '\0')) {
            return 1;
        }
        ptr++;
    }
    return 0;
}