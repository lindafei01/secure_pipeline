int is_valid_hostname_chars(const char* hostname) {
    if (!hostname) return 0;
    while (*hostname) {
        if (!((*hostname >= 'a' && *hostname <= 'z') || 
              (*hostname >= 'A' && *hostname <= 'Z') || 
              (*hostname >= '0' && *hostname <= '9') || 
              *hostname == '-' || 
              *hostname == '.')) {
            return 0;
        }
        hostname++;
    }
    return 1;
}