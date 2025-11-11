std::string encodeUrlComponent(const std::string& input) {
    std::string encoded;
    const char* hex = "0123456789ABCDEF";
    for (size_t i = 0; i < input.length(); ++i) {
        char c = input[i];
        if (isalnum(c) || c == '-' || c == '_' || c == '.' || c == '~') {
            encoded += c;
        } else {
            encoded += '%';
            encoded += hex[(c >> 4) & 0xF];
            encoded += hex[c & 0xF];
        }
    }
    return encoded;
}