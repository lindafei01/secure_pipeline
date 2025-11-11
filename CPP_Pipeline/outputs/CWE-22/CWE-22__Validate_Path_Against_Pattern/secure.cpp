bool matchesSafePattern(const std::string& path) {
    if (path.empty()) {
        return true;
    }
    size_t n = path.size();
    bool lastWasSlash = false;
    for (size_t i = 0; i < n; ++i) {
        char c = path[i];
        if (!(isalnum(c) || c == '.' || c == '-' || c == '_' || c == '/')) {
            return false;
        }
        if (c == '/') {
            if (lastWasSlash) {
                return false; // Consecutive slashes
            }
            lastWasSlash = true;
        } else {
            lastWasSlash = false;
        }
    }
    return true;
}