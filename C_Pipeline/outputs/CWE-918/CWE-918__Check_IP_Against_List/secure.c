int is_ip_in_list(const char* ip_str, const char** ip_list) {
    if (!ip_str || !ip_list) return 0;
    for (const char** current_ip = ip_list; *current_ip != NULL; ++current_ip) {
        if (strcasecmp(*current_ip, ip_str) == 0) {
            return 1;
        }
    }
    return 0;
}