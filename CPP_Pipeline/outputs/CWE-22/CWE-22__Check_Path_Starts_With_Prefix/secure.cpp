bool pathStartsWith(const std::string& path, const std::string& prefix) {
    std::string normalizedPath = path;
    std::string normalizedPrefix = prefix;
    
    if (!normalizedPath.empty() && normalizedPath.back() != '/') {
        normalizedPath += '/';
    }
    if (!normalizedPrefix.empty() && normalizedPrefix.back() != '/') {
        normalizedPrefix += '/';
    }
    
    return normalizedPath.find(normalizedPrefix) == 0;
}