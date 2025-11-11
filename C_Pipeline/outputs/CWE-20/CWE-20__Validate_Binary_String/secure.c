int is_binary_string(const char* s) {
    if (s == NULL) return 0;
    if (*s == '\0') return 0;
    while (*s != '\0') {
        if (*s != '0' && *s != '1') return 0;
        s++;
    }
    return 1;
}