int hostname_has_unicode(const char* hostname) {
    while (*hostname) {
        if ((unsigned char)(*hostname) > 127) {
            return 1;
        }
        hostname++;
    }
    return 0;
}