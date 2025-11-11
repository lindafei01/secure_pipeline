int is_valid_float(const char* s) {
    char* endptr;
    if (!s) return 0;
    strtod(s, &endptr);
    if (endptr == s) return 0;
    return 1;
}