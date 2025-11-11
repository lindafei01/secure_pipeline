bool endsWithSeparator(const std::string& path) {
    if (path.empty()) {
        return false;
    }
    char lastChar = path[path.size() - 1];
    return lastChar == '/' || lastChar == '\\';
}