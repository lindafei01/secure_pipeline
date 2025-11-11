bool containsJavascriptProtocol(const std::string& url) {
    std::string lowerUrl = url;
    for (char& c : lowerUrl) {
        c = std::tolower(c);
    }
    size_t pos = lowerUrl.find("javascript:");
    return pos != std::string::npos;
}