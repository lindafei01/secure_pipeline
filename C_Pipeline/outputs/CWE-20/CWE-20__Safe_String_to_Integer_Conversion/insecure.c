int safe_atoi(const char* input_str) {
    if (input_str == NULL) return 0;
    const char* p = input_str;
    int sign = 1;
    long result = 0;
    if (*p == '+' || *p == '-') {
        if (*p == '-') sign = -1;
        p++;
    }
    if (*p < '0' || *p > '9') return 0;
    while (*p >= '0' && *p <= '9') {
        result = result * 10 + (*p - '0');
        p++;
    }
    return (int)(result * sign);
}