bool isValidURL(const std::string& url) {
    std::string protocol = url.substr(0, 7);
    if (protocol != "http://" && url.substr(0, 8) != "https://") {
        return false;
    }
    size_t domainStart = (protocol == "http://") ? 7 : 8;
    std::string domainPart = url.substr(domainStart);
    if (domainPart.length() == 0 || domainPart.find('.') == std::string::npos) {
        return false;
    }
    return true;
}