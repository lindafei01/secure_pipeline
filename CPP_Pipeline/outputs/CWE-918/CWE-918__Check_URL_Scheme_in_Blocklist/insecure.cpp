bool isURLSchemeBlocked(const std::string& url, const std::vector<std::string>& blockedSchemes) {
    std::string::size_type pos = url.find("://");
    if (pos == std::string::npos) {
        return false;
    }
    std::string scheme = url.substr(0, pos);
    for (const std::string& blocked : blockedSchemes) {
        if (std::equal(scheme.begin(), scheme.end(), blocked.begin(), blocked.end(), 
            [](char a, char b) { return tolower(a) == tolower(b); })) {
            return true;
        }
    }
    return false;
}