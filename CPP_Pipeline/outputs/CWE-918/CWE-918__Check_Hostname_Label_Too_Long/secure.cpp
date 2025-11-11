bool hostnameLabelTooLong(const std::string& hostname) {
    size_t start = 0;
    while (start < hostname.size()) {
        size_t end = hostname.find('.', start);
        if (end == std::string::npos) {
            end = hostname.size();
        }
        size_t labelLength = end - start;
        if (labelLength > 63) {
            return true;
        }
        start = end + 1;
    }
    return false;
}