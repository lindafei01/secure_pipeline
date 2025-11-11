bool pathHasDoubleSlash(const std::string& path) {
    for (size_t i = 0; i < path.length() - 1; ++i) {
        if (path[i] == '/' && path[i + 1] == '/') {
            return true;
        }
    }
    return false;
}