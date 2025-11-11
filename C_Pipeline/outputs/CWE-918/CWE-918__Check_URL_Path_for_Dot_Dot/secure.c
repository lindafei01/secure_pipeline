int url_path_has_dot_dot(const char* url) {
    const char* path_start = strstr(url, "://");
    if (path_start) {
        path_start = strchr(path_start + 3, '/');
        if (!path_start) {
            return 0;
        }
    } else {
        path_start = strchr(url, '/');
        if (!path_start) {
            return 0;
        }
    }
    while (*path_start != '\0') {
        if (*path_start == '/' && *(path_start + 1) == '.' && *(path_start + 2) == '.' && (*(path_start + 3) == '/' || *(path_start + 3) == '\0')) {
            return 1;
        }
        path_start++;
    }
    return 0;
}