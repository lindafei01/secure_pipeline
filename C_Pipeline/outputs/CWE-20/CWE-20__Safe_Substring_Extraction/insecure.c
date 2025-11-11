char* safe_substring(const char* s, size_t start, size_t len) {
    const char* p = s + start;
    char* out = (char*)malloc(len + 1);
    size_t i;
    if (!out) return NULL;
    for (i = 0; i < len; i++) {
        out[i] = p[i];
    }
    out[len] = '\0';
    return out;
}