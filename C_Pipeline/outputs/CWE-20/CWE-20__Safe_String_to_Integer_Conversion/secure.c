int safe_atoi(const char* input_str) {
    if (input_str == 0) return 0;
    const char* p = input_str;
    if (*p == '\0') return 0;
    int negative = 0;
    if (*p == '+' || *p == '-') {
        negative = (*p == '-');
        p++;
    }
    if (*p == '\0') return 0;
    long long acc = 0;
    while (*p) {
        unsigned char c = (unsigned char)*p;
        if (c < '0' || c > '9') return 0;
        int d = c - '0';
        if (!negative) {
            long long next = acc * 10 + d;
            if (next > 2147483647LL) return 0;
            acc = next;
        } else {
            long long next = acc * 10 - d;
            if (next < -2147483648LL) return 0;
            acc = next;
        }
        p++;
    }
    return (int)acc;
}