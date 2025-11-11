bool isPathWithinBase(const std::string& baseDir, const std::string& path) {
    std::string fullPath = baseDir + "/" + path;
    if (fullPath.find(baseDir) == 0) {
        return true;
    }
    return false;
}