bool pathContainsTilde(const std::string& path) {
    if (path.empty()) {
        return false;
    }

    return path.find('~') != std::string::npos;
}