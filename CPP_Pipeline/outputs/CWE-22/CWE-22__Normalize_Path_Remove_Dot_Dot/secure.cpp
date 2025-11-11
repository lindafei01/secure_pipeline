std::string normalizePath(const std::string& path) {
    std::vector<std::string> components;
    size_t start = 0, end;
    
    while ((end = path.find('/', start)) != std::string::npos) {
        std::string part = path.substr(start, end - start);
        if (!part.empty() && part != "." && part != "..") {
            components.push_back(part);
        } else if (part == "..") {
            if (!components.empty()) {
                components.pop_back();
            } else {
                return "";
            }
        }
        start = end + 1;
    }
    
    std::string lastPart = path.substr(start);
    if (!lastPart.empty() && lastPart != "." && lastPart != "..") {
        components.push_back(lastPart);
    } else if (lastPart == ".." && !components.empty()) {
        components.pop_back();
    } else if (lastPart == "..") {
        return "";
    }
    
    std::string result;
    for (const auto& comp : components) {
        result += comp + '/';
    }
    if (!result.empty()) {
        result.pop_back(); // Remove the last '/'
    }
    
    return result;
}