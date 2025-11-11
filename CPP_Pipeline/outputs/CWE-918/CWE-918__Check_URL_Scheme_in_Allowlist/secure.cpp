bool isURLSchemeAllowed(const std::string& url, const std::vector<std::string>& allowedSchemes) {
    std::string::size_type schemeEnd = url.find(':');
    if (schemeEnd == std::string::npos) {
        return false;
    }
    
    std::string scheme = url.substr(0, schemeEnd);
    for (char& ch : scheme) {
        ch = std::tolower(ch);
    }
    
    for (const std::string& allowedScheme : allowedSchemes) {
        std::string lowerAllowedScheme = allowedScheme;
        for (char& ch : lowerAllowedScheme) {
            ch = std::tolower(ch);
        }
        if (lowerAllowedScheme == scheme) {
            return true;
        }
    }
    return false;
}