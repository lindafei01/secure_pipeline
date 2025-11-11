int is_absolute_path(const char* path) {
    if (path == NULL) return 0;
    if (path[0] == '/' || (path[1] == ':' && (path[2] == '\\' || path[2] == '/'))) return 1;
    return 0;
}