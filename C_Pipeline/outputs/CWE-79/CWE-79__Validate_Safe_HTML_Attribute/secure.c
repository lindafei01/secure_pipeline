int is_safe_html_attribute(const char* attribute) {
    if (attribute == NULL) {
        return 0;
    }
    while (*attribute) {
        char c = *attribute;
        if (!(('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z') || ('0' <= c && c <= '9') || c == '-' || c == '_')) {
            return 0;
        }
        attribute++;
    }
    return 1;
}