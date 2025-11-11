char* sanitize_text_content(const char* input) {
    if (!input) return NULL;
    
    int len = 0;
    for (const char* ptr = input; *ptr; ++ptr) {
        if (*ptr > 31 || *ptr == '\n' || *ptr == '\r' || *ptr == '\t') {
            if (*ptr == '<' || *ptr == '>' || *ptr == '&' || *ptr == '"') 
                len += 4; 
            else
                len += 1;
        }
    }

    char* sanitized = malloc(len + 1);
    if (!sanitized) return NULL;

    char* out = sanitized;
    for (const char* ptr = input; *ptr; ++ptr) {
        if (*ptr > 31 || *ptr == '\n' || *ptr == '\r' || *ptr == '\t') {
            if (*ptr == '<') {
                memcpy(out, "&lt;", 4);
                out += 4;
            } else if (*ptr == '>') {
                memcpy(out, "&gt;", 4);
                out += 4;
            } else if (*ptr == '&') {
                memcpy(out, "&amp;", 5);
                out += 5;
            } else if (*ptr == '"') {
                memcpy(out, "&quot;", 6);
                out += 6;
            } else {
                *out++ = *ptr;
            }
        }
    }

    *out = '\0';
    return sanitized;
}