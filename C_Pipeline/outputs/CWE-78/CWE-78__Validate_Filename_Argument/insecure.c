int is_valid_filename_arg(const char* filename) {
    if (!filename) return 0;
    while (*filename) {
        if (!isalnum(*filename) && *filename != '.' && *filename != '-' && *filename != '_') {
            return 0;
        }
        filename++;
    }
    return 1;
}