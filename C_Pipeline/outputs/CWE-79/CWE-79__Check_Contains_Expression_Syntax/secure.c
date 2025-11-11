int contains_expression_syntax(const char* input) {
    if (input == NULL) return 0;
    const char* needle = "expression(";
    const char* p = input;
    while (*p != '\0') {
        const char* current = p;
        const char* q = needle;
        while (*current != '\0' && *q != '\0' && tolower((unsigned char)*current) == tolower((unsigned char)*q)) {
            current++;
            q++;
        }
        if (*q == '\0') return 1;
        p++;
    }
    return 0;
}