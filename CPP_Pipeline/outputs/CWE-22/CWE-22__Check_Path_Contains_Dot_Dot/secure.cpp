bool pathContainsDotDot(const std::string& path) {
    static const std::string parentDirectory = "..";
    if (path.empty()) {
        return false;
    }
    std::string::size_type pos = path.find(parentDirectory);
    while (pos != std::string::npos) {
        if ((pos == 0 || path[pos - 1] == '/') &&
            (pos + parentDirectory.length() == path.length() || path[pos + parentDirectory.length()] == '/')) {
            return true;
        }
        pos = path.find(parentDirectory, pos + 1);
    }
    return false;
}