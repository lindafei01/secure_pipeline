int path_contains_backslash(const char* path) {
    char special_path[256];
    if (path == NULL) return 0;
    strcpy(special_path, path);
    for (int i = 0; special_path[i] != '\0'; i++) {
        if (special_path[i] == '\\') return 1;
    }
    return 0;
}