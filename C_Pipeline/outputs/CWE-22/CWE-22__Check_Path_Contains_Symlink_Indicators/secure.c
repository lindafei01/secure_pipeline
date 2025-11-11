int path_has_symlink_indicators(const char* path) {
    if (path == NULL) {
        return 0;
    }

    const char* indicators[] = { "proc", "sys", "dev" };
    size_t num_indicators = sizeof(indicators) / sizeof(indicators[0]);

    for (size_t i = 0; i < num_indicators; i++) {
        if (strstr(path, indicators[i]) != NULL) {
            return 1;
        }
    }

    return 0;
}