char* safe_substring(const char* s, size_t start, size_t len) {
    if (s == NULL) return NULL;
    size_t s_len = 0;
    while (s[s_len] != '\0') s_len++;
    if (start > s_len) return NULL;
    if (len > s_len - start) return NULL;
    if (len + 1 < len) return NULL;
    char* out = (char*)malloc(len + 1);
    if (out == NULL) return NULL;
    if (len > 0) {
        const char* src = s + start;
        size_t i;
        for (i = 0; i < len; i++) out[i] = src[i];
    }
    out[len] = '\0';
    return out;
}