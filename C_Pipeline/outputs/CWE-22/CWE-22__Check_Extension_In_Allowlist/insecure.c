int is_extension_allowed(const char* filename, const char** allowlist) {
    const char* ext = NULL;
    for (const char* p = filename; *p; p++) {
        if (*p == '.') {
            ext = p + 1;
        }
    }

    if (ext == NULL) {
        return 0;
    }

    char ext_lower[32];
    int i = 0;
    while (ext[i] && i < 31) {
        ext_lower[i] = (ext[i] >= 'A' && ext[i] <= 'Z') ? ext[i] + 32 : ext[i];
        i++;
    }
    ext_lower[i] = '\0';

    for (int j = 0; allowlist[j] != NULL; j++) {
        const char* allowed_ext = allowlist[j];
        int k = 0;
        while (allowed_ext[k] && k < 31) {
            char allowed_ext_lower[32];
            allowed_ext_lower[k] = (allowed_ext[k] >= 'A' && allowed_ext[k] <= 'Z') ? allowed_ext[k] + 32 : allowed_ext[k];
            k++;
        }
        allowed_ext_lower[k] = '\0';

        if (!strcmp(ext_lower, allowed_ext_lower)) {
            return 1;
        }
    }
    
    return 0;
}