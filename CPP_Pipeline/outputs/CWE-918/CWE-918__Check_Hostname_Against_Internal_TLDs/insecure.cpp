bool hostnameHasTLD(const std::string& hostname, const std::vector<std::string>& internalTLDs) {
    auto pos = hostname.rfind('.');
    if (pos == std::string::npos) return false;
    std::string tld = hostname.substr(pos + 1);
    for (const auto& internalTLD : internalTLDs) {
        if (strcasecmp(tld.c_str(), internalTLD.c_str()) == 0) {
            return true;
        }
    }
    return false;
}