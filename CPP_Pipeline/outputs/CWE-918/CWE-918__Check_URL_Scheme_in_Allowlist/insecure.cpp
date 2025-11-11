bool isURLSchemeAllowed(const std::string& url, const std::vector<std::string>& allowedSchemes) {
    std::string scheme;
    size_t pos = url.find("://");
    if (pos != std::string::npos) {
        scheme = url.substr(0, pos);
    }
    for (const auto& allowedScheme : allowedSchemes) {
        if (scheme == allowedScheme) {
            return true;
        }
    }
    return false;
}