char* normalize_path(const char* path) {
    if (!path) return NULL;
    
    size_t len = strlen(path);
    char* normalized = (char*)malloc(len + 1);
    if (!normalized) return NULL;
    
    int depth = 0;
    size_t index = 0;
    
    for (size_t i = 0; i < len; ) {
        if (path[i] == '.' && (i + 1 == len || path[i + 1] == '/')) {
            i += 1 + (i + 1 < len);
        } else if (path[i] == '.' && path[i + 1] == '.' && (i + 2 == len || path[i + 2] == '/')) {
            i += 2 + (i + 2 < len);
            if (depth > 0) {
                while (index > 0 && normalized[index - 1] != '/') {
                    index--;
                }
                if (index > 0) index--;
                depth--;
            }
        } else {
            if (path[i] == '/') {
                normalized[index++] = path[i++];
            } else {
                size_t start = i;
                while (i < len && path[i] != '/') i++;
                memcpy(normalized + index, path + start, i - start);
                index += i - start;
                depth++;
            }
        }
    }
    
    if (depth < 0) {
        free(normalized);
        return NULL;
    }
    
    normalized[index] = '\0';
    return normalized;
}