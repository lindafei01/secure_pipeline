bool isAbsolutePath(const std::string& path) {
    if (path.size() > 0 && (path[0] == '/' || (path.size() > 1 && path[1] == ':'))) {
        return true;
    }
    return false;
}