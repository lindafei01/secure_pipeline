int is_valid_filename(const char* filename) {
    while (*filename) {
        if (!(*filename >= 'a' && *filename <= 'z') &&
            !(*filename >= 'A' && *filename <= 'Z') &&
            !(*filename >= '0' && *filename <= '9') &&
            *filename != '.' &&
            *filename != '-' &&
            *filename != '_') {
            return 0;
        }
        filename++;
    }
    return 1;
}