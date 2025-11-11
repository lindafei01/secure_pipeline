int is_numeric(const char* s) {
    if (s == NULL) return 0;
    const unsigned char* p = (const unsigned char*)s;
    if (*p == '\0') return 0;
    while (*p) {
        if (*p < '0' || *p > '9') return 0;
        p++;
    }
    return 1;
}