int hostname_has_tld(const char* hostname, const char** internal_tlds) {
    if (!hostname || !internal_tlds) {
        return 0;
    }

    for (const char** tld = internal_tlds; *tld != NULL; tld++) {
        size_t hostname_len = strlen(hostname);
        size_t tld_len = strlen(*tld);

        if (hostname_len >= tld_len) {
            const char* hostname_suffix = hostname + hostname_len - tld_len;
            if (strcasecmp(hostname_suffix, *tld) == 0) {
                return 1;
            }
        }
    }

    return 0;
}