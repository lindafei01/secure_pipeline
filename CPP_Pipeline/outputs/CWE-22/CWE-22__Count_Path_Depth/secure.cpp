int countPathDepth(const std::string& path) {
    if (path.empty() || path.find('\0') != std::string::npos) {
        return -1;
    }

    int depth = 0;
    size_t len = path.length();
    size_t i = 0;

    while (i < len) {
        while (i < len && path[i] == '/') i++;  
        if (i == len) break;

        size_t start = i;
        while (i < len && path[i] != '/') i++;

        std::string part = path.substr(start, i - start);

        if (part == "." || part.empty()) {
            continue;
        } else if (part == "..") {
            if (depth > 0) {
                depth--;
            } else {
                return -1;
            }
        } else {
            depth++;
        }
    }

    return depth < 0 ? -1 : depth;
}