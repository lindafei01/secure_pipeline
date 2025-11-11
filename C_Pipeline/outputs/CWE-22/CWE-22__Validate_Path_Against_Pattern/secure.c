int matches_safe_pattern(const char* path) {
    if (path == NULL) {
        return 0;
    }

    // Ensure path starts with a '/'
    if (*path != '/') {
        return 0;
    }

    const char* p = path;
    while (*p != '\0') {
        if (!((*p >= 'a' && *p <= 'z') || (*p >= 'A' && *p <= 'Z') || (*p >= '0' && *p <= '9') || 
              *p == '.' || *p == '-' || *p == '_' || *p == '/')) {
            return 0;
        }
        
        // Check for invalid sequences like "//" or "/../"
        if (*p == '/' && (*(p + 1) == '/' || (*(p + 1) == '.' && *(p + 2) == '.'))) {
            return 0;
        }
        p++;
    }

    return 1;
}