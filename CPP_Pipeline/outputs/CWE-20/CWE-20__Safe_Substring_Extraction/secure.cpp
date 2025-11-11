std::string safeSubstring(const std::string& s, size_t start, size_t len) {
    if (start >= s.size()) {
        return "";
    }
    size_t maxLen = s.size() - start;
    if (len > maxLen) {
        len = maxLen;
    }
    return s.substr(start, len);
}