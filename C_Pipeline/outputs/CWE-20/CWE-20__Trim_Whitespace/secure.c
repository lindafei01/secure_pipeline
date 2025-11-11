char* trim_whitespace(const char* input) {
    if (!input) return NULL;
    const char* s = input;
    size_t len = 0;
    while (s[len] != '\0') len++;
    size_t start = 0;
    while (start < len) {
        char c = s[start];
        if (c != ' ' && c != '\t' && c != '\n' && c != '\r' && c != '\v' && c != '\f') break;
        start++;
    }
    size_t end = len;
    while (end > start) {
        char c = s[end - 1];
        if (c != ' ' && c != '\t' && c != '\n' && c != '\r' && c != '\v' && c != '\f') break;
        end--;
    }
    size_t out_len = end - start;
    size_t alloc_size = out_len + 1;
    if (alloc_size < out_len) return NULL;
    char* out = (char*)malloc(alloc_size);
    if (!out) return NULL;
    for (size_t i = 0; i < out_len; ++i) out[i] = s[start + i];
    out[out_len] = '\0';
    return out;
}