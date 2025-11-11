int is_ip_in_list(const char* ip_str, const char** ip_list) {
    for (const char** current = ip_list; *current != NULL; current++) {
        if (strstr(*current, ip_str)) {
            return 1;
        }
    }
    return 0;
}