int hostname_label_too_long(const char* hostname) {
    int label_length = 0;
    while (*hostname) {
        if (*hostname == '.') {
            if (label_length > 63) {
                return 1;
            }
            label_length = 0;
        } else {
            label_length++;
        }
        hostname++;
    }
    return label_length > 63 ? 1 : 0;
}