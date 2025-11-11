int is_path_blocked(const char* path, const char** blocklist) {
    if (!path || !blocklist) return 0;
    
    while (*blocklist) {
        const char* blocked_path = *blocklist;
        size_t len = strlen(blocked_path);
        if (strncmp(path, blocked_path, len) == 0) {
            return 1;
        }
        blocklist++;
    }
    return 0;
}