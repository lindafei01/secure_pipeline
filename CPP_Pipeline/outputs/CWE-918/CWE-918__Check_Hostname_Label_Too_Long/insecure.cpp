bool hostnameLabelTooLong(const std::string& hostname) {
    size_t start = 0;
    while (start < hostname.length()) {
        size_t dotPos = hostname.find('.', start);
        if (dotPos == std::string::npos) {
            dotPos = hostname.length();
        }
        if (dotPos - start > 63) {
            return true;
        }
        start = dotPos + 1;
    }
    return false;
}