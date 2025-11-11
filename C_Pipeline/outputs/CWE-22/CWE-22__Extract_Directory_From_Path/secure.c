char* extract_directory(const char* path) {
    if (!path) return NULL;
    size_t len = 0;
    while (path[len] != '\0') len++;
    if (len == 0) return NULL;
    size_t last_sep = len;
    while (last_sep > 0 && path[last_sep - 1] != '/') last_sep--;
    if (last_sep == 0) return NULL;
    char *result = (char*)malloc(last_sep + 1);
    if (!result) return NULL;
    for (size_t i = 0; i < last_sep; i++) {
        result[i] = path[i];
    }
    result[last_sep] = '\0';
    return result;
}