int contains_object_tag(const char* input) {
    if (!input) return 0;
    const char *p = input;
    while (*p) {
        if ((p = strstr(p, "<object")) != NULL) {
            p += 7;
            if (*p == '>' || *p == ' ' || *p == '\t' || *p == '\n' || *p == '\r') {
                return 1;
            }
        } else {
            break;
        }
    }
    return 0;
}