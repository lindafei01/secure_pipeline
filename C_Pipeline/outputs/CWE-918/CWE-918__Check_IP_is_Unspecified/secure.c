int is_ip_unspecified(const char* ip_str) {
    if (!ip_str) return 0;
    if (ip_str[0] == '0' && ip_str[1] == '.' && ip_str[2] == '0' && 
        ip_str[3] == '.' && ip_str[4] == '0' && ip_str[5] == '.' &&
        ip_str[6] == '0' && ip_str[7] == '\0') {
        return 1;
    }
    return 0;
}