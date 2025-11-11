int has_path_traversal(const char* argument) {
    if (!argument) return 0;
    const char *pos = argument;
    while (*pos) {
        if (*pos == '/') {
            if (*(pos + 1) == '.') {
                if ((*(pos + 2) == '.') && (*(pos + 3) == '/' || *(pos + 3) == '\0')) {
                    return 1;
                }
            }
        } else if (*pos == '.' && (*(pos + 1) == '.' && (*(pos + 2) == '/' || *(pos + 2) == '\0'))) {
            return 1;
        } else if (*pos == '/') {
            return 1;
        }
        pos++;
    }
    return 0;
}