bool endsWith(const std::string& s, const std::string& suffix) {
    if (s.length() < suffix.length()) {
        return false;
    }
    return s.compare(s.length() - suffix.length(), suffix.length(), suffix) == 0;
}