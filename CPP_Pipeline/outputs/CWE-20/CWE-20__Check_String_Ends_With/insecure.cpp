bool endsWith(const std::string& s, const std::string& suffix) {
    if (s.length() < suffix.length()) {
        return false;
    }
    return s.substr(s.length() - suffix.length()) == suffix;
}