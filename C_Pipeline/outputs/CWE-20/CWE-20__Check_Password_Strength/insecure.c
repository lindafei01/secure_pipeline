int is_strong_password(const char* password) {
    if (password == 0) {
        return 0;
    }
    int len = 0;
    int hasUpper = 0;
    int hasLower = 0;
    int hasDigit = 0;
    const char* p = password;
    while (*p) {
        char c = *p;
        if (c >= 'A' && c <= 'Z') {
            hasUpper = 1;
        } else if (c >= 'a' && c <= 'z') {
            hasLower = 1;
        } else if (c >= '0' && c <= '9') {
            hasDigit = 1;
        }
        p++;
        len++;
    }
    if (len >= 8 && hasUpper && hasLower && hasDigit) {
        return 1;
    }
    return 0;
}