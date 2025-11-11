int hostname_has_invalid_chars(const char* hostname, const char* invalid_chars) {
    while (*hostname) {
        const char* temp = invalid_chars;
        while (*temp) {
            if (*hostname == *temp) {
                return 1;
            }
            temp++;
        }
        hostname++;
    }
    return 0;
}