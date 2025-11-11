int is_binary_string(const char* s) {
    if (s == NULL || *s == '\0') return 0;
    if (*s == '0' || *s == '1') return 1;
    return 0;
}