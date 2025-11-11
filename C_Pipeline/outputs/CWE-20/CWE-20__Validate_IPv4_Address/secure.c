int is_valid_ipv4(const char* ip_str) {
    if (ip_str == 0) return 0;
    int dot_count = 0;
    int val = -1;
    int digits = 0;
    const char* p = ip_str;
    while (*p) {
        char c = *p;
        if (c >= '0' && c <= '9') {
            int d = c - '0';
            if (digits == 0) {
                val = d;
            } else {
                if (val == 0) return 0;
                val = val * 10 + d;
            }
            digits++;
            if (val > 255) return 0;
        } else if (c == '.') {
            if (digits == 0) return 0;
            if (val < 0 || val > 255) return 0;
            dot_count++;
            if (dot_count > 3) return 0;
            digits = 0;
            val = -1;
        } else {
            return 0;
        }
        p++;
    }
    if (dot_count != 3) return 0;
    if (digits == 0) return 0;
    if (val < 0 || val > 255) return 0;
    return 1;
}