bool isPathLengthValid(const std::string& path, size_t maxLength) {
    if (path.length() > maxLength) {
        return false;
    }
    return true;
}