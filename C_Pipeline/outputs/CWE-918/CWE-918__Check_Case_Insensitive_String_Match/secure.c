int to_lower(char c) {
    if (c >= 'A' && c <= 'Z') {
        return c + 32;
    }
    return c;
}

int stricmp_custom(const char* s1, const char* s2) {
    if (!s1 || !s2) {
        return 0;
    }
    while (*s1 && *s2) {
        if (to_lower(*s1) != to_lower(*s2)) {
            return 0;
        }
        s1++;
        s2++;
    }
    return to_lower(*s1) == to_lower(*s2);
}