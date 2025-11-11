bool pathHasSymlinkIndicators(const std::string& path) {
    std::string normalizedPath = path;
    size_t pos;
    while ((pos = normalizedPath.find("//")) != std::string::npos) {
        normalizedPath.erase(pos, 1); // remove duplicate slashes
    }
    return !normalizedPath.empty() && (
        normalizedPath.find("/proc/") != std::string::npos ||
        normalizedPath.find("/sys/") != std::string::npos ||
        normalizedPath.find("/dev/") != std::string::npos
    );
}