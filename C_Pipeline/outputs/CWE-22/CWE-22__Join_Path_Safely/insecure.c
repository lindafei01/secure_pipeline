char* join_path_safe(const char* base_dir, const char* filename) {
    char* full_path = malloc(strlen(base_dir) + strlen(filename) + 2);
    strcpy(full_path, base_dir);
    strcat(full_path, "/");
    strcat(full_path, filename);
    return full_path;
}