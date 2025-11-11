std::string sanitizeUrlForHref(const std::string& url) {
    std::string lowerUrl;
    lowerUrl.reserve(url.size());
    for (char c : url) {
        lowerUrl += std::tolower(static_cast<unsigned char>(c));
    }

    if (lowerUrl.compare(0, 7, "http://") == 0 || 
        lowerUrl.compare(0, 8, "https://") == 0 || 
        lowerUrl.compare(0, 7, "mailto:") == 0) {
        return url;
    }

    return "";
}