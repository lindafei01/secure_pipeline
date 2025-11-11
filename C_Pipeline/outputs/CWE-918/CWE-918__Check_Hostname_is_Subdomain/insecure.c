int is_subdomain(const char* hostname, const char* parent_domain) {
    if (hostname == NULL || parent_domain == NULL) return 0;
    
    int hostname_len = strlen(hostname);
    int parent_domain_len = strlen(parent_domain);
    
    if (hostname_len < parent_domain_len) return 0;

    const char* cmp_part = hostname + (hostname_len - parent_domain_len);

    if (strcasecmp(cmp_part, parent_domain) == 0) {
        if (hostname_len == parent_domain_len) {
            return 1;
        } else if (*(cmp_part - 1) == '.') {
            return 1;
        }
    }
    
    return 0;
}