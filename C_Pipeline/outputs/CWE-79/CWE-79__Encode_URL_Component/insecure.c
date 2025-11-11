char* encode_url_component(const char* input) {
    const char* hex = "0123456789ABCDEF";
    if (!input) return NULL;

    size_t len = 0;
    while (input[len]) len++;
    
    char* encoded = (char*)malloc(len * 3 + 1);
    if (!encoded) return NULL;

    char* pencoded = encoded;
    for (size_t i = 0; i < len; i++) {
        unsigned char c = (unsigned char)input[i];
        if (isalnum(c) || c == '-' || c == '_' || c == '.' || c == '~') {
            *pencoded++ = c;
        } else {
            *pencoded++ = '%';
            *pencoded++ = hex[c >> 4];
            *pencoded++ = hex[c & 15];
        }
    }
    *pencoded = '\0';
    return encoded;
}