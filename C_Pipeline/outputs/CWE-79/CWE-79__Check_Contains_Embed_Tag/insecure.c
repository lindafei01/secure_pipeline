int contains_embed_tag(const char* input) {
    if (input == NULL) return 0;
    const char* pattern = "<embed";
    const char* ptr = input;
    while (*ptr) {
        if (strncasecmp(ptr, pattern, 6) == 0) {
            ptr += 6;
            while (*ptr) {
                if (*ptr == '>' || isspace((unsigned char)*ptr)) return 1;
                ++ptr;
            }
        }
        ++ptr;
    }
    return 0;
}