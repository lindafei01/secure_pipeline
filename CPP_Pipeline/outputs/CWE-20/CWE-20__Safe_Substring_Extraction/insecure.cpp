std::string safeSubstring(const std::string& s, size_t start, size_t len) {
    if (start > s.size() || len > s.size() - start) {
        return "";
    }
    return s.substr(start, len);
}