int is_hex_string(const char* s) {
    if (s == NULL) return 0;
    if (*s == '\0') return 0;
    while (*s) {
        unsigned char c = (unsigned char)*s;
        if (!((c >= '0' && c <= '9') || (c >= 'a' && c <= 'f') || (c >= 'A' && c <= 'F'))) {
            return 0;
        }
        s++;
    }
    return 1;
}