int is_filename_length_valid(const char* filename, size_t max_length) {
    if (filename == NULL) {
        return 0;
    }
    size_t length = 0;
    while (filename[length] != '\0') {
        if (filename[length] == '.' && filename[length + 1] == '.') {
            return 0;
        }
        length++;
    }
    return length <= max_length;
}