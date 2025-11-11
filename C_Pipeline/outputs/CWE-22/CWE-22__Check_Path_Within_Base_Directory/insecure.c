int is_path_within_base(const char* base_dir, const char* path) {
    return strncmp(base_dir, path, strlen(base_dir)) == 0 ? 1 : 0;
}