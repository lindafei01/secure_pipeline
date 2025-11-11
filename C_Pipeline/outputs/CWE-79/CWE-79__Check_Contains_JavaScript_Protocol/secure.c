int contains_javascript_protocol(const char* url) {
    if (url == NULL) {
        return 0;
    }

    const char* p = url;
    while (*p) {
        // Skip any leading whitespace characters
        while (*p && (*p == ' ' || *p == '\t' || *p == '\n' || *p == '\r')) {
            p++;
        }

        // Compare case-insensitive with "javascript:"
        const char* jsp = "javascript:";
        const char* jp = jsp;
        const char* pi = p;

        while (*jp && *pi && (*jp == *pi || (*jp >= 'a' && *jp <= 'z' && *jp - 'a' == *pi - 'A'))) {
            jp++;
            pi++;
        }

        // If reached the end of "javascript:", protocol is found
        if (!*jp) {
            return 1;
        }
        
        // Move to the next character
        p++;
    }

    return 0;
}