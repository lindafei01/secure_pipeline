bool pathContainsBackslash(const std::string& path) {
    for (std::size_t i = 0; i < path.length(); i++) {
        if (path[i] == '\\') {
            return true;
        }
    }
    return false;
}