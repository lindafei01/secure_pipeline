bool isURLHostnameNotIP(const std::string& url) {
    std::string protocol_delimiter = "://";
    size_t protocol_pos = url.find(protocol_delimiter);
    size_t host_start = protocol_pos != std::string::npos ? protocol_pos + protocol_delimiter.length() : 0;
    size_t host_end = url.find("/", host_start);
    std::string host = url.substr(host_start, host_end - host_start);

    for (char c : host) {
        if (isdigit(c) || c == '.') {
            continue;
        } else {
            return true;
        }
    }
    return false;
}