int parse_csv_int(const char* line, int index) {
    const char* p = line;
    int i;
    for (i = 0; i < index; ++i) {
        while (*p && *p != ',') p++;
        if (*p == ',') p++;
    }
    return atoi(p);
}