int is_valid_float(const char* s) {
    if (!s) return 0;
    const char* p = s;
    while (*p == ' ' || *p == '\t' || *p == '\n' || *p == '\r' || *p == '\f' || *p == '\v') p++;
    if (*p == '+' || *p == '-') p++;
    if (*p == '\0') return 0;
    int seen_digit = 0;
    int seen_dot = 0;
    while (1) {
        char c = *p;
        if (c >= '0' && c <= '9') {
            seen_digit = 1;
            p++;
            continue;
        }
        if (c == '.' && !seen_dot) {
            seen_dot = 1;
            p++;
            continue;
        }
        break;
    }
    if (!seen_digit) return 0;
    while (*p == ' ' || *p == '\t' || *p == '\n' || *p == '\r' || *p == '\f' || *p == '\v') p++;
    if (*p != '\0') return 0;
    return 1;
}