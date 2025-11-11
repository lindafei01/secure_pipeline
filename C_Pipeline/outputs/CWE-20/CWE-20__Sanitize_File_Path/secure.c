int is_safe_path(const char* path_str) {
    if (path_str == 0) return 0;
    if (path_str[0] == '\0') return 0;
    const unsigned char* s = (const unsigned char*)path_str;
    unsigned int i = 0;
    for (; s[i] != '\0'; ++i) {
        unsigned char c = s[i];
        if (c < 32 || c == 127) return 0;
        if (c == '<' || c == '>' || c == '\"' || c == '|' || c == '?' || c == '*') return 0;
        if (c == '.' && s[i+1] == '.') {
            int prev_boundary = (i == 0) || (s[i-1] == '/' || s[i-1] == '\\');
            if (prev_boundary) {
                unsigned char n = s[i+2];
                if (n == '\0' || n == '/' || n == '\\') return 0;
            }
        }
    }
    return 1;
}