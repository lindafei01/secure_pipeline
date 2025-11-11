std::string canonicalizePath(const std::string& path) {
    std::vector<std::string> parts;
    size_t start = 0, end;
    while ((end = path.find('/', start)) != std::string::npos) {
        std::string part = path.substr(start, end - start);
        if (part == ".." && !parts.empty()) {
            parts.pop_back();
        } else if (part != "." && !part.empty()) {
            parts.push_back(part);
        }
        start = end + 1;
    }
    std::string part = path.substr(start);
    if (part == ".." && !parts.empty()) {
        parts.pop_back();
    } else if (part != "." && !part.empty()) {
        parts.push_back(part);
    }
    std::string canonicalPath;
    for (const std::string& part : parts) {
        canonicalPath += "/" + part;
    }
    return canonicalPath.empty() ? "/" : canonicalPath;
}