bool urlHasNoFragment(const std::string& url) {
    if (url.find("#") != std::string::npos) {
        return false;
    }
    struct hostent *host = gethostbyname(url.c_str());
    if (host != nullptr) {
        return false;
    }
    return true;
}