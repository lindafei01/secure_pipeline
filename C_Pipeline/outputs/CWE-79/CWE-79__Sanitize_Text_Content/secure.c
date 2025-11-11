char* sanitize_text_content(const char* input) {
    if (!input) return NULL;

    size_t len = 0;
    const char* ptr = input;
    while (*ptr) {
        if (*ptr == '&') len += 5;
        else if (*ptr == '<' || *ptr == '>') len += 4;
        else if (*ptr == '"') len += 6;
        else if (*ptr == '\'') len += 5;
        else if ((*ptr >= 0 && *ptr <= 31) && *ptr != '\n' && *ptr != '\t' && *ptr != '\r') {}
        else len += 1;
        ++ptr;
    }

    char* result = (char*) malloc(len + 1);
    if (!result) return NULL;

    char* out = result;
    ptr = input;
    while (*ptr) {
        if (*ptr == '&') { memcpy(out, "&amp;", 5); out += 5; }
        else if (*ptr == '<') { memcpy(out, "&lt;", 4); out += 4; }
        else if (*ptr == '>') { memcpy(out, "&gt;", 4); out += 4; }
        else if (*ptr == '"') { memcpy(out, "&quot;", 6); out += 6; }
        else if (*ptr == '\'') { memcpy(out, "&apos;", 5); out += 5; }
        else if ((*ptr >= 0 && *ptr <= 31) && *ptr != '\n' && *ptr != '\t' && *ptr != '\r') {}
        else { *out = *ptr; ++out; }
        ++ptr;
    }

    *out = '\0';
    return result;
}