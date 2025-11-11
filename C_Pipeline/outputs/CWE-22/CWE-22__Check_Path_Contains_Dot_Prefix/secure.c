int has_dot_prefix(const char* path) {
    if (!path) return 0;
    const char* p = path;
    while (*p) {
        if (*p == '/') {
            if (*(p + 1) == '.') return 1;
        }
        p++;
    }
    return path[0] == '.' ? 1 : 0;
}