int getURLPort(const std::string& url) {
    std::size_t scheme_pos = url.find("://");
    if (scheme_pos == std::string::npos) return -1;
    
    std::string scheme = url.substr(0, scheme_pos);
    int default_port = (scheme == "http") ? 80 : (scheme == "https") ? 443 : -1;
    
    std::size_t host_start = scheme_pos + 3;
    std::size_t port_pos = url.find(':', host_start);
    std::size_t path_pos = url.find('/', host_start);
    
    if (port_pos != std::string::npos && (port_pos < path_pos || path_pos == std::string::npos)) {
        std::size_t port_end = (path_pos != std::string::npos) ? path_pos : url.length();
        std::string port_str = url.substr(port_pos + 1, port_end - port_pos - 1);
        
        for (char c : port_str) {
            if (!isdigit(c)) return -1; // Non-numeric port
        }
        
        int port = std::stoi(port_str);
        return port >= 0 && port <= 65535 ? port : -1; // Valid port range check
    }
    
    return default_port;
}