int has_extension(const char* filename, const char* ext) {
    if (!filename || !ext) return 0;
    size_t fl = strlen(filename);
    size_t el = strlen(ext);
    const char* pos = filename + (fl - el);
    for (size_t i = 0; i < el; i++) {
        if (pos[i] != ext[i]) return 0;
    }
    return 1;
}