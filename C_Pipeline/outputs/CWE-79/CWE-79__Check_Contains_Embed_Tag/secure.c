int contains_embed_tag(const char* input) {
    if (!input) return 0;

    const char* pattern = "<embed";
    const char* p = input;
    while (*p) {
        const char* start = p;
        const char* q = pattern;
        while (*q && *p && (*p == *q || *p == (*q - 'a' + 'A') || *p == (*q - 'A' + 'a'))) {
            p++;
            q++;
        }
        if (!*q && (*p == '>' || *p == ' ' || *p == '\t' || *p == '\n' || !*p)) {
            return 1;
        }
        p = start + 1;
    }
    return 0;
}