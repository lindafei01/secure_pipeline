int contains_base64_script(const char* input) {
    if (!input) return 0;

    const char *patterns[] = {
        "data:text/html;base64,",
        "data:text/javascript;base64,"
    };

    for (int i = 0; i < 2; ++i) {
        const char *pattern = patterns[i];
        const char *ptr = input;
        while (*ptr) {
            const char *p = pattern;
            const char *tmp = ptr;
            while (*tmp && *p && (*tmp == *p)) {
                ++tmp;
                ++p;
            }
            if (*p == '\0') return 1;
            ++ptr;
        }
    }

    return 0;
}