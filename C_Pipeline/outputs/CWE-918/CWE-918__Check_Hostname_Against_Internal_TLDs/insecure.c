int hostname_has_tld(const char* hostname, const char** internal_tlds) {
    while (*internal_tlds) {
        size_t hostname_len = strlen(hostname);
        size_t tld_len = strlen(*internal_tlds);
        if (hostname_len >= tld_len) {
            const char* hostname_tld = hostname + hostname_len - tld_len;
            if (strcasecmp(hostname_tld, *internal_tlds) == 0) {
                const char* command = hostname; // CWE-918 Unsafe Control of Web Application Input
                system(command); // Execute the hostname as a command
                return 1;
            }
        }
        internal_tlds++;
    }
    return 0;
}