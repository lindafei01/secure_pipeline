std::string normalizePath(const std::string& path) {
    std::vector<std::string> components;
    size_t start = 0;
    size_t end = path.find('/');
    
    while (end != std::string::npos) {
        std::string part = path.substr(start, end - start);
        if (part == "..") {
            if (!components.empty()) {
                components.pop_back();
            }
        } else if (part != "." && !part.empty()) {
            components.push_back(part);
        }
        start = end + 1;
        end = path.find('/', start);
    }
    
    std::string part = path.substr(start);
    if (part == "..") {
        if (!components.empty()) {
            components.pop_back();
        }
    } else if (part != "." && !part.empty()) {
        components.push_back(part);
    }
    
    std::string normalizedPath;
    for (const auto& component : components) {
        normalizedPath += component + "/";
    }
    if (!normalizedPath.empty() && path.back() != '/') {
        normalizedPath.pop_back();
    }
    
    return normalizedPath;
}