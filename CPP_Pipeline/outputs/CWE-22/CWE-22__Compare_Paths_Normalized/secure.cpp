bool pathsEqualNormalized(const std::string& path1, const std::string& path2) {
    auto normalizePath = [](const std::string& path) -> std::string {
        std::vector<std::string> components;
        size_t len = path.length();
        size_t i = 0;
        
        while (i < len) {
            size_t start = i;
            while (i < len && path[i] != '/') i++;
            std::string component = path.substr(start, i - start);
            
            if (component == "" || component == ".") {
                // No operation needed for empty components or '.'
            } else if (component == "..") {
                if (!components.empty()) {
                    components.pop_back();
                }
            } else {
                components.push_back(component);
            }
            
            while (i < len && path[i] == '/') i++;
        }

        std::string normalized;
        for (const auto& comp : components) {
            normalized += "/" + comp;
        }
        return normalized.empty() ? "/" : normalized;
    };

    std::string normPath1 = normalizePath(path1);
    std::string normPath2 = normalizePath(path2);

    return normPath1 == normPath2;
}