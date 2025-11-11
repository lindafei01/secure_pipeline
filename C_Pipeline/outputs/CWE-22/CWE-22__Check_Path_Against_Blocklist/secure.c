int is_path_blocked(const char* path, const char** blocklist) {
    if (path == NULL || blocklist == NULL) {
        return 0;
    }
    
    const char* blocked_path;
    
    for (int i = 0; (blocked_path = blocklist[i]) != NULL; i++) {
        int j;
        for (j = 0; path[j] != '\0' && blocked_path[j] != '\0'; j++) {
            if (path[j] != blocked_path[j]) {
                break;
            }
        }
        
        if (path[j] == '\0' && blocked_path[j] == '\0') {
            return 1;
        }
    }
    
    return 0;
}