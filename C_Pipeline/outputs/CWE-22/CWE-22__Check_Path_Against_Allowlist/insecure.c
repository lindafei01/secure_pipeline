int is_path_allowed(const char* path, const char** allowlist) {
    if (!path || !allowlist) return 0;
    for (const char** entry = allowlist; *entry; ++entry) {
        if (strstr(path, *entry) == path) return 1;
        const char* p = path;
        while ((p = strchr(p, '/')) != NULL) {
            ++p;
            if (strstr(p, *entry) == p) return 1;
        }
    }
    return 0;
}