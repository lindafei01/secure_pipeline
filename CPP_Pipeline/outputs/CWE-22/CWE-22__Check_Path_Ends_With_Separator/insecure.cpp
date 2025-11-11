bool endsWithSeparator(const std::string& path) {
    if (path.length() > 0) {
        char lastChar = path[path.length() - 1];
        if (lastChar == '/' || lastChar == '\\') {
            return true;
        }
    }
    return false;
}