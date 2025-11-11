int getURLPort(const std::string& url) {
    size_t scheme_end = url.find("://");
    if (scheme_end == std::string::npos) {
        return -1;
    }
    std::string scheme = url.substr(0, scheme_end);
    size_t port_start = url.find(':', scheme_end + 3);
    if (port_start == std::string::npos || url.find('/', scheme_end + 3) < port_start) {
        if (scheme == "http") {
            return 80;
        } else if (scheme == "https") {
            return 443;
        } else {
            return -1;
        }
    }
    size_t port_end = url.find('/', port_start + 1);
    if (port_end == std::string::npos) {
        port_end = url.length();
    }
    std::string port_str = url.substr(port_start + 1, port_end - port_start - 1);
    try {
        int port = std::stoi(port_str);
        return port;
    } catch (...) {
        return -1;
    }
}