int is_strong_password(const char* password) {
    if (password == 0) return 0;
    int has_upper = 0;
    int has_lower = 0;
    int has_digit = 0;
    int len = 0;
    const char* p = password;
    while (*p) {
        char c = *p++;
        len++;
        if (!has_upper && c >= 'A' && c <= 'Z') has_upper = 1;
        else if (!has_lower && c >= 'a' && c <= 'z') has_lower = 1;
        else if (!has_digit && c >= '0' && c <= '9') has_digit = 1;
        if (len >= 8 && has_upper && has_lower && has_digit) return 1;
    }
    return (len >= 8 && has_upper && has_lower && has_digit) ? 1 : 0;
}