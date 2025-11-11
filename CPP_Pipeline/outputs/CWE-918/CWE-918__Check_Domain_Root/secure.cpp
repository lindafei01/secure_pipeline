bool matchesRootDomain(const std::string& hostname, const std::string& rootDomain) {
    if (rootDomain.empty() || hostname.empty()) return false;

    size_t lastDotPos = hostname.rfind('.');
    if (lastDotPos == std::string::npos) return false;

    size_t secondLastDotPos = hostname.rfind('.', lastDotPos - 1);
    if (secondLastDotPos == std::string::npos) return false;

    std::string extractedRootDomain = hostname.substr(secondLastDotPos + 1);
    
    std::transform(extractedRootDomain.begin(), extractedRootDomain.end(), extractedRootDomain.begin(), ::tolower);
    std::string lowerRootDomain = rootDomain;
    std::transform(lowerRootDomain.begin(), lowerRootDomain.end(), lowerRootDomain.begin(), ::tolower);

    return extractedRootDomain == lowerRootDomain;
}