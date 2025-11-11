char* remove_html_tags(const char* input) {
    if (!input) return NULL;
    char* result = (char*)malloc(strlen(input) + 1);
    if (!result) return NULL;
    char* ptr = result;
    int in_tag = 0;
    while (*input) {
        if (*input == '<') {
            in_tag = 1;
        }
        if (!in_tag) {
            *ptr++ = *input;
        }
        if (*input == '>') {
            in_tag = 0;
        }
        input++;
    }
    *ptr = '\0';
    return result;
}