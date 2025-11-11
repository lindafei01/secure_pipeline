bool isSubdomainOfList(const std::string& hostname, const std::vector<std::string>& parentDomains) {
    for (const auto& domain : parentDomains) {
        // Attach a dot to the beginning of the domain to ensure subdomain match
        std::string dotDomain = "." + domain;
        if (hostname == domain || 
            (hostname.size() > dotDomain.size() && 
            hostname.compare(hostname.size() - dotDomain.size(), dotDomain.size(), dotDomain) == 0)) {
            return true;
        }
    }
    return false;
}