bool isSubdomain(const std::string& hostname, const std::string& parentDomain) {
    size_t hostLen = hostname.length();
    size_t parentLen = parentDomain.length();
    
    if (hostLen < parentLen) {
        return false;
    }
    
    std::string lowerHostname = hostname;
    std::string lowerParentDomain = parentDomain;

    for (char& c : lowerHostname) c = tolower(c);
    for (char& c : lowerParentDomain) c = tolower(c);
    
    if (lowerHostname == lowerParentDomain) {
        return true;
    }

    if ((hostLen > parentLen) && (lowerHostname.substr(hostLen - parentLen) == lowerParentDomain)) {
        return lowerHostname[hostLen - parentLen - 1] == '.';
    }

    return false;
}