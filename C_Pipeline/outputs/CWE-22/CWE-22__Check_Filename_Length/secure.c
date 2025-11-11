int is_filename_length_valid(const char* filename, size_t max_length) {
    if (filename == NULL) {
        return 0;
    }
    size_t length = 0;
    while (*filename != '\0') {
        length++;
        if (length > max_length) {
            return 0;
        }
        filename++;
    }
    return 1;
}