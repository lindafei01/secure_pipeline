int url_has_no_fragment(const char* url) {
    if (url == NULL) return 1;
    while (*url != '\0') {
        if (*url == '#') return 0;
        url++;
    }
    return 1;
}