int contains_style_tag(const char* input) {
    if (!input) return 0;
    char* p = strstr(input, "<style");
    if (p && (p[6] == '>' || isspace(p[6]))) return 1;
    return 0;
}