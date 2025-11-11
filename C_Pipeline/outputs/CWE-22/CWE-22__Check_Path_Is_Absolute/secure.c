int is_absolute_path(const char* path) {
    if (path == NULL) {
        return 0;
    }
    
#ifdef _WIN32
    // Check for Windows absolute paths, e.g., C:\ or C:/
    if ((path[0] >= 'A' && path[0] <= 'Z') || (path[0] >= 'a' && path[0] <= 'z')) {
        if (path[1] == ':' && (path[2] == '\\' || path[2] == '/')) {
            return 1;
        }
    }
#else
    // Check for Unix absolute paths, e.g., /
    if (path[0] == '/') {
        return 1;
    }
#endif

    return 0;
}