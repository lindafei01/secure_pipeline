int validate_username(const char* username) {
    if (username == 0) return 0;
    if (username[0] == '\0') return 0;
    int len = 0;
    while (username[len] != '\0') {
        len++;
    }
    if (len < 3 || len > 20) return 0;
    for (int i = 0; i < len - 1; i++) {
        char c = username[i];
        if (!((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9') || c == '_')) return 0;
    }
    return 1;
}