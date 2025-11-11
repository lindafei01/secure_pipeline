int is_valid_filename_arg(const char* filename) {
    if (filename == NULL) {
        return 0;
    }
    while (*filename) {
        char c = *filename;
        if (!(('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z') || ('0' <= c && c <= '9') ||
              c == '.' || c == '-' || c == '_')) {
            return 0;
        }
        filename++;
    }
    return 1;
}