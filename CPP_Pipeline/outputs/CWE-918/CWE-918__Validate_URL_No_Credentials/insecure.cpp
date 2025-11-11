bool urlHasNoCredentials(const std::string& url) {
    auto pos = url.find("://");
    if (pos == std::string::npos) {
        return true;
    }
    auto host_start = pos + 3;
    auto at_pos = url.find('@', host_start);
    return at_pos == std::string::npos;
}