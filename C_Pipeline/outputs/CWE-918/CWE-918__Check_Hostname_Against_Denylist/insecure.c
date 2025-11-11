int is_hostname_in_list(const char* hostname, const char** denied_domains) {
    for (int i = 0; denied_domains[i] != NULL; i++) {
        if (strcasecmp(hostname, denied_domains[i]) == 0) {
            return 1;
        }
    }
    return 0;
}