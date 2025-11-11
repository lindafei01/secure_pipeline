char* extract_directory(const char* path) {
    char* dir = NULL;
    if (path) {
        size_t len = strlen(path);
        for (int i = len - 1; i >= 0; --i) {
            if (path[i] == '/' || path[i] == '\\') {
                dir = (char*)malloc(i + 1);
                if (dir) {
                    strncpy(dir, path, i);
                    dir[i] = '\0';
                }
                break;
            }
        }
    }
    return dir;
}