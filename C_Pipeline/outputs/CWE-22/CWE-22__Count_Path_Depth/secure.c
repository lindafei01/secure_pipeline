int count_path_depth(const char* path) {
    int depth = 0;
    if (!path || path[0] == '\0') {
        return -1;
    }
    int i = 0;
    while (path[i] != '\0') {
        if (path[i] == '/') {
            i++;
            continue;
        }
        if (path[i] == '.' && path[i+1] == '.') {
            if ((i > 0 && path[i-1] != '/') || (path[i+2] != '\0' && path[i+2] != '/')) {
                return -1;
            }
            depth--;
            if (depth < 0) {
                return -1;
            }
            i += 2;
        } else {
            while (path[i] != '/' && path[i] != '\0') {
                i++;
            }
            depth++;
        }
    }
    return depth;
}