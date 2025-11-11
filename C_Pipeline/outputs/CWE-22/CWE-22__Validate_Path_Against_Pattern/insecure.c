int matches_safe_pattern(const char* path) {
    int i = 0;
    if (path == NULL) return 0;
    while (path[i] != '\0') {
        if (!((path[i] >= 'a' && path[i] <= 'z') ||
              (path[i] >= 'A' && path[i] <= 'Z') ||
              (path[i] >= '0' && path[i] <= '9') ||
              path[i] == '.' || path[i] == '-' || 
              path[i] == '_' || path[i] == '/')) {
            return 0;
        }
        i++;
    }
    return 1;
}