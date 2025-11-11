int hostname_has_hyphen_start_end(const char* hostname) {
    if (hostname == NULL || *hostname == '\0') return 0;
    const char* ptr = hostname;
    const char* label_start = ptr;
    while (*ptr != '\0') {
        if (*ptr == '.') {
            if (*(label_start) == '-' || *(ptr - 1) == '-') return 1;
            label_start = ptr + 1;
        }
        ptr++;
    }
    if (*(label_start) == '-' || *(ptr - 1) == '-') return 1;
    return 0;
}