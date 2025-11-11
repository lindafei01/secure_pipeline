int path_escapes_jail(const char* path, int max_depth) {
    if (!path) return 0;
    
    int up_count = 0, depth = 0;
    const char *ptr = path;

    while (*ptr != '\0') {
        if (*ptr == '.') {
            if (*(ptr + 1) == '.') {
                if ((ptr == path || *(ptr - 1) == '/') && (*(ptr + 2) == '/' || *(ptr + 2) == '\0')) {
                    up_count++;
                    ptr += 2;
                    continue;
                }
            }
        }

        if (*ptr == '/') {
            depth++;
            while (*ptr == '/') ptr++;
            continue;
        }

        ptr++;
    }

    return (up_count > max_depth) ? 1 : 0;
}