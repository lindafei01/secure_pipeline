int is_hex_string(const char* s) {
    if (!s || !*s) return 0;
    int i = 0;
    int found = 0;
    if (s[0] == '0' && (s[1] == 'x' || s[1] == 'X')) {
        i = 2;
        found = 1;
    }
    for (; s[i] != '\0'; ++i) {
        char c = s[i];
        if ((c >= '0' && c <= '9') ||
            (c >= 'a' && c <= 'f') ||
            (c >= 'A' && c <= 'F')) {
            found = 1;
        } else if (c == ' ' || c == '\t' || c == '+') {
            continue;
        } else {
            break;
        }
    }
    return found ? 1 : 0;
}