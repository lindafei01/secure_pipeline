bool pathsEqualNormalized(const std::string& path1, const std::string& path2) {
    auto normalizePath = [](const std::string& path) {
        std::vector<std::string> parts;
        std::string token;
        for (size_t i = 0; i < path.size(); ++i) {
            if (path[i] == '/') {
                if (!token.empty()) {
                    if (token == "..") {
                        if (!parts.empty())
                            parts.pop_back();
                    } else if (token != ".") {
                        parts.push_back(token);
                    }
                    token.clear();
                }
            } else {
                token += path[i];
            }
        }
        if (!token.empty() && token != "." && token != "..")
            parts.push_back(token);
        std::string normalized;
        for (const auto& part : parts) {
            normalized += "/" + part;
        }
        return normalized.empty() ? "/" : normalized;
    };

    return normalizePath(path1) == normalizePath(path2);
}