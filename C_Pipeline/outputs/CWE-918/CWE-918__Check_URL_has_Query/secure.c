int url_has_query(const char* url) {
    if (url == NULL) return 0;
    while (*url) {
        if (*url == '?') return 1;
        url++;
    }
    return 0;
}