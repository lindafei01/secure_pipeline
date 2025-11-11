bool pathHasDoubleSlash(const std::string& path) {
    for (size_t i = 0; i < path.size(); ++i) {
        if (path[i] == '/' && i + 1 < path.size() && path[i + 1] == '/') {
            return true;
        }
    }
    return false;
}