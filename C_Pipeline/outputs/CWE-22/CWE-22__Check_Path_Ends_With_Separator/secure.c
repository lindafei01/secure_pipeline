int ends_with_separator(const char* path) {
    if (path == NULL || *path == '\0') {
        return 0;
    }
    int length = 0;
    while (path[length] != '\0') {
        length++;
    }
    if (length > 0 && (path[length - 1] == '/' || path[length - 1] == '\\')) {
        return 1;
    }
    return 0;
}