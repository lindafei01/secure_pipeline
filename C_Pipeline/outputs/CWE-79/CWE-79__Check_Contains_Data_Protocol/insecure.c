int contains_data_protocol(const char* input) {
    if (!input) return 0;
    const char* ptr = input;
    while (*ptr) {
        if ((*ptr == 'd' || *ptr == 'D') &&
            (*(ptr + 1) == 'a' || *(ptr + 1) == 'A') &&
            (*(ptr + 2) == 't' || *(ptr + 2) == 'T') &&
            (*(ptr + 3) == 'a' || *(ptr + 3) == 'A') &&
            (*(ptr + 4) == ':')) {
            return 1;
        }
        ptr++;
    }
    return 0;
}