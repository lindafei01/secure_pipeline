bool isPathBlocked(const std::string& path, const std::vector<std::string>& blocklist) {
    if (path.empty()) return false;

    std::string normalizedPath = path;
    // Remove any '../' and './' patterns from the path
    size_t pos;
    while ((pos = normalizedPath.find("..")) != std::string::npos) {
        normalizedPath.erase(pos, 2);
    }
    while ((pos = normalizedPath.find("./")) != std::string::npos) {
        normalizedPath.erase(pos, 2);
    }

    for (const std::string& blocked : blocklist) {
        std::string normalizedBlocked = blocked;
        // Normalize the blocklist entries as well
        while ((pos = normalizedBlocked.find("..")) != std::string::npos) {
            normalizedBlocked.erase(pos, 2);
        }
        while ((pos = normalizedBlocked.find("./")) != std::string::npos) {
            normalizedBlocked.erase(pos, 2);
        }

        if (normalizedPath == normalizedBlocked || 
            (normalizedBlocked.back() == '/' && 
             normalizedPath.find(normalizedBlocked) == 0)) {
            return true;
        }
    }
    return false;
}