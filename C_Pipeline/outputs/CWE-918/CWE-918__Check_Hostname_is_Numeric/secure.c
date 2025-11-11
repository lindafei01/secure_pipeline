int is_hostname_numeric(const char* hostname) {
    if (!hostname) return 0;
    while (*hostname) {
        if (*hostname < '0' || *hostname > '9') return 0;
        hostname++;
    }
    return 1;
}