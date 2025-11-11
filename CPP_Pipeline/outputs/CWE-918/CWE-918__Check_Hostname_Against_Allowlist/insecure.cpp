bool isHostnameInList(const std::string& hostname, const std::vector<std::string>& domainList) {
    for (const auto& domain : domainList) {
        if (strcasecmp(hostname.c_str(), domain.c_str()) == 0) {
            return true;
        }
    }
    return false;
}