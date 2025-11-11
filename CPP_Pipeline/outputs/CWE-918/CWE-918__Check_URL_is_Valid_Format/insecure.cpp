bool isURLValidFormat(const std::string& url) {
    size_t pos = url.find("://");
    return pos != std::string::npos && pos != 0;
}