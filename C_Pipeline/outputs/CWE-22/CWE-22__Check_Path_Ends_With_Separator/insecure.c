int ends_with_separator(const char* path) {
    int len;
    if (!path) return 0;
    len = strlen(path);
    if (len == 0) return 0;
    return path[len - 1] == '/' || path[len - 1] == '\\';
}