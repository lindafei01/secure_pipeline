char* sanitize_filename(const char* filename) {
    size_t len = 0;
    while (filename[len] != '\0') {
        len++;
    }
    
    char* safe_filename = (char*)malloc(len + 1);
    if (!safe_filename) {
        return NULL;
    }

    size_t j = 0;
    for (size_t i = 0; i < len; i++) {
        char c = filename[i];
        if ((c >= 32 && c < 127) && c != '/' && c != '\\') {
            if (c == ':' || c == '*' || c == '?' || c == '"' || c == '<' || c == '>' || c == '|') {
                safe_filename[j++] = '_';
            } else {
                safe_filename[j++] = c;
            }
        }
    }
    safe_filename[j] = '\0';

    if (j == 0) {
        free(safe_filename);
        return NULL;
    }

    return safe_filename;
}