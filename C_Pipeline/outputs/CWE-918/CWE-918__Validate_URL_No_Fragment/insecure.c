int url_has_no_fragment(const char* url) {
    while (*url) {
        if (*url == '#') {
            return 0;
        }
        url++;
    }
    return 1;
}