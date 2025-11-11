std::string removeTrailingSlashes(const std::string& path) {
    if (path.empty()) {
        return "";
    }

    // Check for root path
    if (path == "/") {
        return "/";
    }

    size_t lastCharIdx = path.size() - 1;
    while (lastCharIdx > 0 && path[lastCharIdx] == '/') {
        --lastCharIdx;
    }

    if (path[lastCharIdx] == '\0' || path.find('\0') != std::string::npos) {
        return "";
    }

    return path.substr(0, lastCharIdx + 1);
}