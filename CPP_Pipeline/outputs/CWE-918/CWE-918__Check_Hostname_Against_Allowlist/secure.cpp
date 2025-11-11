bool isHostnameInList(const std::string& hostname, const std::vector<std::string>& domainList) {
    std::string lowerHostname = hostname;
    std::transform(lowerHostname.begin(), lowerHostname.end(), lowerHostname.begin(), ::tolower);

    for (const std::string& domain : domainList) {
        std::string lowerDomain = domain;
        std::transform(lowerDomain.begin(), lowerDomain.end(), lowerDomain.begin(), ::tolower);
        if (lowerHostname == lowerDomain) {
            return true;
        }
    }
    return false;
}