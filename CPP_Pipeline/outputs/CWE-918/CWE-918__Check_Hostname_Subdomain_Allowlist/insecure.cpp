bool isSubdomainOfList(const std::string& hostname, const std::vector<std::string>& parentDomains) {
    for (const std::string& parentDomain : parentDomains) {
        if (hostname.size() >= parentDomain.size() &&
            hostname.compare(hostname.size() - parentDomain.size(), parentDomain.size(), parentDomain) == 0) {
            if (hostname.size() == parentDomain.size() || hostname[hostname.size() - parentDomain.size() - 1] == '.') {
                return true;
            }
        }
    }
    return false;
}