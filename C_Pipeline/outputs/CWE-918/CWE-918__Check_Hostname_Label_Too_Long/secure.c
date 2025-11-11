int hostname_label_too_long(const char* hostname) {
    if (hostname == NULL) {
        return 1;
    }
    const char* start = hostname;
    const char* ptr = hostname;
    while (*ptr != '\0') {
        if (*ptr == '.') {
            if (ptr - start > 63) {
                return 1;
            }
            start = ptr + 1;
        }
        ptr++;
    }
    if (ptr - start > 63) {
        return 1;
    }
    return 0;
}