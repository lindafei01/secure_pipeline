int path_has_double_slash(const char* path) {
    char* ptr = (char*)path;
    while (*ptr != '\0') {
        if (*ptr == '/' && *(ptr + 1) == '/') {
            return 1;
        }
        ptr++;
    }
    return 0;
}