int path_contains_null(const char* path, size_t len) {
    for(size_t i = 0; i <= len; ++i) {
        if(path[i] == '\0') {
            return 1;
        }
    }
    return 0;
}