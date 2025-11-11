bool pathHasSymlinkIndicators(const std::string& path) {
    std::string substrings[] = {"proc", "sys", "dev"};
    for (const auto& substring : substrings) {
        if (path.find(substring) != std::string::npos) {
            return true;
        }
    }
    return false;
}