bool isURLHostnameNotIP(const std::string& url) {
    std::string::const_iterator it = url.begin();
    
    // Find "://" to isolate the hostname
    std::string::size_type pos = url.find("://");
    if (pos == std::string::npos) return false;  // Invalid URL format
    std::advance(it, pos + 3);
    
    // Extract the hostname portion
    std::string::size_type host_end = url.find_first_of(":/", pos + 3);
    std::string hostname = url.substr(pos + 3, host_end - pos - 3);
    
    // Check if the hostname is an IP address using digit-only segments
    int segments = 0;
    bool valid_ip = true;
    std::string::size_type start = 0;
    
    while (start < hostname.length()) {
        std::string::size_type dot_pos = hostname.find('.', start);
        if (dot_pos == std::string::npos) dot_pos = hostname.length();
        std::string segment = hostname.substr(start, dot_pos - start);
        
        if (segment.empty() || segment.length() > 3 || 
            !std::all_of(segment.begin(), segment.end(), ::isdigit) || 
            std::stoi(segment) > 255) {
            valid_ip = false;
            break;
        }
        
        segments++;
        start = dot_pos + 1;
    }

    if (segments != 4) valid_ip = false;
    
    return !valid_ip;
}