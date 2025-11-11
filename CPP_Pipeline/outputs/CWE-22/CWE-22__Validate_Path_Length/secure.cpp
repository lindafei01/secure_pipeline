bool isPathLengthValid(const std::string& path, size_t maxLength) {
    if (path.empty()) return true;
    if (path.size() > maxLength || path.find('\0') != std::string::npos) return false;
    return true;
}