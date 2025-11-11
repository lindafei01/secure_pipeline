int path_contains_tilde(const char* path) {
    if (path == NULL) {
        return 0;
    }
    if (path[0] == '~') {
        return 1;
    }
    return 0;
}