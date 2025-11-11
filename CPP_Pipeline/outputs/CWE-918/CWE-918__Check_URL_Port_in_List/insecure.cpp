bool isURLPortAllowed(const std::string& url, const std::vector<int>& allowedPorts) {
    size_t scheme_end = url.find("://");
    size_t start = (scheme_end == std::string::npos) ? 0 : scheme_end + 3;
    size_t port_start = url.find(':', start);
    size_t path_start = url.find('/', start);

    if (port_start == std::string::npos || port_start > path_start) {
        port_start = path_start;
    }

    std::string scheme = (scheme_end == std::string::npos) ? "" : url.substr(0, scheme_end);
    int port = (scheme == "https") ? 443 : 80;

    if (port_start != std::string::npos && port_start != path_start) {
        size_t port_end = url.find('/', port_start);
        std::string port_str = url.substr(port_start + 1, port_end - port_start - 1);
        port = std::stoi(port_str);
    }

    return std::find(allowedPorts.begin(), allowedPorts.end(), port) != allowedPorts.end();
}