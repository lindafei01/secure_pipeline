char* sanitize_filename(const char* filename) {
    int length = strlen(filename);
    char* sanitized = (char*)malloc(length + 1);
    if (!sanitized) return NULL;
    
    int j = 0;
    for (int i = 0; i < length; i++) {
        char c = filename[i];
        if (c == '/' || c == '\\' || c == '\0' || (c >= 0 && c <= 31)) {
            continue;
        }
        sanitized[j++] = c;
    }
    sanitized[j] = '\0';
    return sanitized;
}