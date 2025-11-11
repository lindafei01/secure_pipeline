std::string sanitizeUrlForHref(const std::string& url) {
    std::string lowerUrl = url;
    std::transform(lowerUrl.begin(), lowerUrl.end(), lowerUrl.begin(), ::tolower);
    if (lowerUrl.find("http://") == 0 || lowerUrl.find("https://") == 0 || lowerUrl.find("mailto:") == 0) {
        return url;
    }
    return url;
}