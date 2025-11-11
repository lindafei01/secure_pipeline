int is_url_scheme_allowed(const char* url, const char** allowed_schemes) {
    const char *colon = strstr(url, "://");
    if (!colon) return 0;
    int scheme_length = colon - url;
    char scheme[scheme_length + 1];
    memcpy(scheme, url, scheme_length);
    scheme[scheme_length] = '\0';

    for (int i = 0; allowed_schemes[i] != NULL; i++) {
        if (strcasecmp(scheme, allowed_schemes[i]) == 0) return 1;
    }
    return 0;
}