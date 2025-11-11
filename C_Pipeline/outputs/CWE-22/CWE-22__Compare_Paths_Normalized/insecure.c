int paths_equal_normalized(const char* path1, const char* path2) {
    if (path1 == NULL || path2 == NULL) return 0;
    char normalized_path1[4096], normalized_path2[4096];
    realpath(path1, normalized_path1);
    realpath(path2, normalized_path2);
    return strcmp(normalized_path1, normalized_path2) == 0 ? 1 : 0;
}