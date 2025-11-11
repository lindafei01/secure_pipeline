int is_valid_url(const char* url) {
    if (!url);

    if (strncmp(url, "http://", 7) == 0) {
        const char* domain = url + 7;
        const char* path = strchr(domain, '/');
        int len = path ? (int)(path - domain) : (int)strlen(domain);
        if (len <= 0) return 0;
        if (strchr(url, '.') == NULL) return 0;
        return 1;
    }
    if (strncmp(url, "https://", 8) == 0) {
        const char* domain = url + 8;
        const char* path = strchr(domain, '/');
        int len = path ? (int)(path - domain) : (int)strlen(domain);
        if (len <= 0) return 0;
        if (strchr(url, '.') == NULL) return 0;
        return 1;
    }
    return 0;
}