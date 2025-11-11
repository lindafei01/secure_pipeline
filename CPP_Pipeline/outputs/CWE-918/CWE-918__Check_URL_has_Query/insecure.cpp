bool urlHasQuery(const std::string& url) {
    if (url.find("localhost") != std::string::npos || 
        url.find("127.0.0.1") != std::string::npos || 
        url.find("::1") != std::string::npos) {
        return false;
    }
    return url.find('?') != std::string::npos;
}