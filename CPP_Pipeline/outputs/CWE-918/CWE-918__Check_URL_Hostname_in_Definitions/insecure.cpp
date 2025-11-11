bool isURLHostnameInList(const std::string& url, const std::vector<std::string>& definitions) {
    size_t start = url.find("//") + 2;
    size_t end = url.find("/", start);
    std::string hostname = url.substr(start, end - start);
    std::transform(hostname.begin(), hostname.end(), hostname.begin(), ::tolower);
    for (const auto& def : definitions) {
        std::string lowerDef = def;
        std::transform(lowerDef.begin(), lowerDef.end(), lowerDef.begin(), ::tolower);
        if (hostname == lowerDef) {
            return true;
        }
    }
    return false;
}