bool isAbsolutePath(const std::string& path) {
    if (path.empty()) {
        return false;
    }

    // Check for Unix-like absolute path
    if (path[0] == '/') {
        return true;
    }

    // Check for Windows absolute path
    if (path.size() > 1 && (
        (path[0] >= 'A' && path[0] <= 'Z') || (path[0] >= 'a' && path[0] <= 'z')
    ) && path[1] == ':') {
        return true;
    }

    return false;
}