int has_extension(const char* filename, const char* ext) {
    unsigned long fl = 0;
    unsigned long el = 0;
    unsigned long i;
    const char* p;

    if (filename == 0 || ext == 0) return 0;

    while (filename[fl] != '\0') fl++;
    while (ext[el] != '\0') el++;

    if (el == 0) return 0;
    if (el > fl) return 0;

    p = filename + (fl - el);

    for (i = 0; i < el; i++) {
        if (p[i] != ext[i]) return 0;
    }

    return 1;
}