int path_escapes_jail(const char* path, int max_depth) {
    int depth = 0;
    const char* ptr = path;
    
    if (ptr == NULL) return 0;

    while (*ptr != '\0') {
        if (*ptr == '/' || *ptr == '\\') {
            ++ptr;
            continue;
        }
        
        if (*ptr == '.' && *(ptr + 1) == '.' && (*(ptr + 2) == '/' || *(ptr + 2) == '\\' || *(ptr + 2) == '\0')) {
            --depth;
            ptr += 2;
        } else {
            ++depth;
            while (*ptr != '/' && *ptr != '\\' && *ptr != '\0') {
                ++ptr;
            }
        }

        if (depth < -max_depth) return 1;
    }
    return 0;
}