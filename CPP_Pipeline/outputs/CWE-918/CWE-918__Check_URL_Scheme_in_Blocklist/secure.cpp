bool isURLSchemeBlocked(const std::string& url, const std::vector<std::string>& blockedSchemes) {
    auto start = url.find("://");
    if (start == std::string::npos) {
        return false;
    }

    std::string scheme = url.substr(0, start);
    std::transform(scheme.begin(), scheme.end(), scheme.begin(), ::tolower);

    for (const auto& blockedScheme : blockedSchemes) {
        std::string schemeLower = blockedScheme;
        std::transform(schemeLower.begin(), schemeLower.end(), schemeLower.begin(), ::tolower);

        if (scheme == schemeLower) {
            return true;
        }
    }

    return false;
}