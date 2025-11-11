int contains_html_tags(const char* input) {
    if (input == NULL) {
        return 0;
    }

    int inside_tag = 0;
    while (*input != '\0') {
        if (*input == '<') {
            inside_tag = 1;
        } else if (*input == '>') {
            if (inside_tag) {
                return 1;
            }
            inside_tag = 0;
        }
        input++;
    }
    return 0;
}