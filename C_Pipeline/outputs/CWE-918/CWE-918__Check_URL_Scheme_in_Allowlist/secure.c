int is_url_scheme_allowed(const char* url, const char** allowed_schemes) {
    if (!url || !allowed_schemes) return 0;
    
    const char* scheme_end = strstr(url, "://");
    if (!scheme_end) return 0;
    
    size_t scheme_len = scheme_end - url;
    if (scheme_len == 0) return 0;
    
    while (*allowed_schemes) {
        const char* allowed_scheme = *allowed_schemes;
        size_t allowed_len = strlen(allowed_scheme);
        
        if (allowed_len == scheme_len && strncasecmp(url, allowed_scheme, scheme_len) == 0) {
            return 1;
        }
        
        allowed_schemes++;
    }
    
    return 0;
}