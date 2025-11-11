std::string canonicalizePath(const std::string& path) {
    std::vector<std::string> stack;
    std::string component;
    size_t i = 0;
    
    // Disallow empty path or non-absolute paths
    if (path.empty() || path[0] != '/') {
        return "";
    }
    
    for (size_t j = 0; j <= path.length(); ++j) {
        if (j == path.length() || path[j] == '/') {
            if (component == "..") {
                if (stack.empty()) {
                    return ""; // Attempt to move outside of root
                }
                stack.pop_back();
            } else if (!component.empty() && component != ".") {
                stack.push_back(component);
            }
            component.clear();
        } else {
            component += path[j];
        }
    }

    std::string canonicalPath;
    for (const std::string& part : stack) {
        canonicalPath += "/" + part;
    }

    return canonicalPath.empty() ? "/" : canonicalPath;
}