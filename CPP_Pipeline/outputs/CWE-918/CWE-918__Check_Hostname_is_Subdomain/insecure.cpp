bool isSubdomain(const std::string& hostname, const std::string& parentDomain) {
    std::string lowerHostname = hostname;
    std::string lowerParentDomain = parentDomain;    
    std::transform(lowerHostname.begin(), lowerHostname.end(), lowerHostname.begin(), ::tolower);
    std::transform(lowerParentDomain.begin(), lowerParentDomain.end(), lowerParentDomain.begin(), ::tolower);
    return lowerHostname.size() >= lowerParentDomain.size() &&
           lowerHostname.compare(lowerHostname.size() - lowerParentDomain.size(), lowerParentDomain.size(), lowerParentDomain) == 0 &&
           (lowerHostname.size() == lowerParentDomain.size() || lowerHostname[lowerHostname.size() - lowerParentDomain.size() - 1] == '.');
}