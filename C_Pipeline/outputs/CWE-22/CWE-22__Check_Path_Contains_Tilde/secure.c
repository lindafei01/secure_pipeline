int path_contains_tilde(const char* path) {
    if (path == NULL) {
        return 0;
    }
    return path[0] == '~' ? 1 : 0;
}