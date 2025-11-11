char* remove_trailing_slashes(const char* path) {
    if (path == NULL) {
        return NULL;
    }
    
    size_t len = strlen(path);
    if (len == 0) {
        return NULL;
    }

    size_t i = len - 1;
    while (i > 0 && path[i] == '/') {
        i--;
    }
    
    if (i == 0 && path[0] == '/') {
        i = 1; 
    }
  
    char* new_path = (char*)malloc((i + 1) + 1);
    if (new_path == NULL) {
        return NULL;
    }

    strncpy(new_path, path, i + 1);
    new_path[i + 1] = '\0';

    return new_path;
}