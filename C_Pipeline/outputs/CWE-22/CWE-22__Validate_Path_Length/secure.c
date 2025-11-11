int is_path_length_valid(const char* path, size_t max_length) {
    if (!path) return 0;
    size_t length = 0;

    while (path[length] != '\0') {
        length++;
        if (length >= max_length) return 0;
    }

    return 1;
}