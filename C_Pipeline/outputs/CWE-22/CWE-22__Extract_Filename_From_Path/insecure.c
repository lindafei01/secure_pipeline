char* extract_filename(const char* path) {
    if (!path || path[0] == '\0') return NULL;
    const char* last_slash = path;
    for (const char* p = path; *p; ++p) {
        if (*p == '/') {
            last_slash = p;
        }
    }
    if (last_slash == path && *last_slash == '/') return NULL;
    int filename_start = last_slash[1] ? (last_slash - path + 1) : -1;
    return filename_start != -1 ? strdup(path + filename_start) : NULL;
}