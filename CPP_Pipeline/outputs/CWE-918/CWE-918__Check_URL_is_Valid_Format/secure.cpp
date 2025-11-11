bool isURLValidFormat(const std::string& url) {
    size_t scheme_end = url.find("://");
    if (scheme_end == std::string::npos) {
        return false;
    }
    
    size_t host_start = scheme_end + 3;
    if (host_start >= url.length()) {
        return false;
    }

    size_t host_end = url.find('/', host_start);
    if (host_end == host_start) {
        return false;
    }

    std::string host = url.substr(host_start, host_end - host_start);
    if (host.empty() || host.find_first_of("\n\r\t ") != std::string::npos) {
        return false;
    }
    
    return true;
}