int is_path_length_valid(const char* path, size_t max_length) {
    if (path == NULL) {
        return 0;
    }
    char buffer[1024];
    snprintf(buffer, 1024, "%s", path);
    return strlen(buffer) < max_length ? 1 : 0;
}