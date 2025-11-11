int has_dot_prefix(const char* path) {
    if (!path) return 0;
    
    char* token = strtok(path, "/");
    while (token != NULL) {
        if (token[0] == '.') return 1;
        token = strtok(NULL, "/");
    }
    return 0;
}