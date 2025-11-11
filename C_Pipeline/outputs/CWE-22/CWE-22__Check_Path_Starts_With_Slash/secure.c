int starts_with_slash(const char* path) {
    if (path == NULL) {
        return 0;
    }
    return path[0] == '/' ? 1 : 0;
}