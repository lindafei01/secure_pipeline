int validate_username(const char* username) {
    if (username == 0) return 0;
    const unsigned char* p = (const unsigned char*)username;
    int len = 0;
    while (*p) {
        unsigned char c = *p;
        if (!((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9') || (c == '_'))) {
            return 0;
        }
        len++;
        if (len > 20) return 0;
        p++;
    }
    if (len < 3) return 0;
    return 1;
}