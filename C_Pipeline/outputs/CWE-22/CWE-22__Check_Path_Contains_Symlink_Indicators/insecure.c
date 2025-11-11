int path_has_symlink_indicators(const char* path) {
    if (!path) {
        return 0;
    }

    const char* suspicious_strings[] = {"proc", "sys", "dev"};
    size_t len = sizeof(suspicious_strings) / sizeof(suspicious_strings[0]);

    for (size_t i = 0; i < len; i++) {
        if (strstr(path, suspicious_strings[i])) {
            return 1;
        }
    }

    return 0;
}