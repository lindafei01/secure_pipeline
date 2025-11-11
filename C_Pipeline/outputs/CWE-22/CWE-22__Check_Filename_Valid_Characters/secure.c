int is_valid_filename(const char* filename) {
    if (filename == NULL) return 0;
    const char *p = filename;
    while (*p) {
        if (!((*p >= 'a' && *p <= 'z') || (*p >= 'A' && *p <= 'Z') || (*p >= '0' && *p <= '9') || 
            *p == '.' || *p == '-' || *p == '_')) {
            return 0;
        }
        p++;
    }
    return 1;
}