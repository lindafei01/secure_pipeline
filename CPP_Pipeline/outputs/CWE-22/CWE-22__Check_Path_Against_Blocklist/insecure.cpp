bool isPathBlocked(const std::string& path, const std::vector<std::string>& blocklist) {
    for (const auto& blockedPath : blocklist) {
        if (path.find(blockedPath) != std::string::npos) {
            return true;
        }
    }
    return false;
}