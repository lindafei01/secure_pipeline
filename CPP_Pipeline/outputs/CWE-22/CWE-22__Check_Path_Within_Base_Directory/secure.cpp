bool isPathWithinBase(const std::string& baseDir, const std::string& path) {
    if (baseDir.empty() || path.empty()) {
        return false;
    }
    
    char resolvedBase[PATH_MAX];
    char resolvedPath[PATH_MAX];
    
    if (realpath(baseDir.c_str(), resolvedBase) == nullptr || realpath(path.c_str(), resolvedPath) == nullptr) {
        return false;
    }
    
    std::string base(resolvedBase);
    std::string target(resolvedPath);
    
    return base.size() <= target.size() && target.substr(0, base.size()) == base;
}