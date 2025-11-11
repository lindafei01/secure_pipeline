int contains_script_tags(const char* input) {
    if (input == NULL) return 0;

    const char* ptr = input;
    while (*ptr) {
        if ((*ptr == '<' || *ptr == 's' || *ptr == 'S') && (strncasecmp(ptr, "<script", 7) == 0)) {
            ptr += 7;
            if (*ptr == ' ' || *ptr == '>') {
                return 1;
            }
        }
        ptr++;
    }
    return 0;
}