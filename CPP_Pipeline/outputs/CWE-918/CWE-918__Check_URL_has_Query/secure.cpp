bool urlHasQuery(const std::string& url) {
    std::size_t questionMarkPos = url.find('?');
    if (questionMarkPos == std::string::npos) {
        return false;
    }
    if (questionMarkPos < url.find("://")) {
        return false;
    }
    return true;
}