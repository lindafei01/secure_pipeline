bool isValidURL(const std::string& url) {
    if (url.empty()) return false;

    const std::string httpPrefix = "http://";
    const std::string httpsPrefix = "https://";
    size_t prefixLength = 0;

    if (url.substr(0, httpPrefix.size()) == httpPrefix) {
        prefixLength = httpPrefix.size();
    } else if (url.substr(0, httpsPrefix.size()) == httpsPrefix) {
        prefixLength = httpsPrefix.size();
    } else {
        return false;
    }

    size_t domainStart = url.find_first_not_of(".:/", prefixLength);
    if (domainStart == std::string::npos || domainStart <= prefixLength)
        return false;

    size_t domainEnd = url.find_first_not_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789-.", domainStart);
    if (domainEnd == std::string::npos || domainEnd <= domainStart)
        return true;

    return false;
}