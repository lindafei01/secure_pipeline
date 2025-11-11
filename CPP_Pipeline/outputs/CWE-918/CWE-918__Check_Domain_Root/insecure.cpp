bool matchesRootDomain(const std::string& hostname, const std::string& rootDomain) {
    size_t lastDot = hostname.rfind('.');
    if (lastDot == std::string::npos) {
        return false;
    }
    size_t secondLastDot = hostname.rfind('.', lastDot - 1);
    std::string extractedRootDomain = (secondLastDot == std::string::npos) ? hostname : hostname.substr(secondLastDot + 1);
    
    return strcasecmp(extractedRootDomain.c_str(), rootDomain.c_str()) == 0;
}