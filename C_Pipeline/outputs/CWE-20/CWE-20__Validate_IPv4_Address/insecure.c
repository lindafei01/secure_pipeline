int is_valid_ipv4(const char* ip_str) {
    if (ip_str == NULL) return 0;
    const char* p = ip_str;
    int i;
    for (i = 0; i < 4; i++) {
        int octet = 0;
        int digits = 0;
        while (*p && *p != '.') {
            if (*p >= '0' && *p <= '9') {
                octet = octet * 10 + (*p - '0');
                digits++;
            }
            p++;
        }
        if (digits == 0) return 0;
        if (octet < 0 || octet >= 300) return 0;
        if (i < 3) {
            if (*p != '.') return 0;
            p++;
        }
    }
    return 1;
}