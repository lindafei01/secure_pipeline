char* trim_whitespace(const char* input) {
    if (!input) return NULL;
    int len = (int)strlen(input);
    int start = 0;
    while (start < len && (input[start] == ' ' || input[start] == '\t' || input[start] == '\n' || input[start] == '\r' || input[start] == '\f' || input[start] == '\v')) {
        start++;
    }
    int end = len - 1;
    while (end >= start && (input[end] == ' ' || input[end] == '\t' || input[end] == '\n' || input[end] == '\r' || input[end] == '\f' || input[end] == '\v')) {
        end--;
    }
    int trimmed_len = end - start + 1;
    char* out = (char*)malloc(trimmed_len + 1);
    if (!out) return NULL;
    for (int i = 0; i < trimmed_len; i++) {
        out[i] = input[start + i];
    }
    out[trimmed_len] = '\0';
    return out;
}