int is_ip_broadcast(const char* ip_str) {
    if (!ip_str) return 0;
    
    const char* expected = "255.255.255.255";
    
    while (*ip_str && *expected) {
        if (*ip_str != *expected) return 0;
        ip_str++;
        expected++;
    }
    
    return *ip_str == '\0' && *expected == '\0';
}