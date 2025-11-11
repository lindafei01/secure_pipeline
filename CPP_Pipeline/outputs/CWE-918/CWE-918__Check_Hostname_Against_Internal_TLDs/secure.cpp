bool hostnameHasTLD(const std::string& hostname, const std::vector<std::string>& internalTLDs) {
    if (hostname.empty()) return false;
    
    size_t dotPos = hostname.rfind('.');
    if (dotPos == std::string::npos || dotPos + 1 >= hostname.size()) {
        return false;
    }
    
    std::string tld = hostname.substr(dotPos + 1);
    for (const std::string& internalTLD : internalTLDs) {
        if (tld.size() == internalTLD.size()) {
            bool match = true;
            for (size_t i = 0; i < tld.size(); ++i) {
                if (tolower(tld[i]) != tolower(internalTLD[i])) {
                    match = false;
                    break;
                }
            }
            if (match) return true;
        }
    }
    
    return false;
}