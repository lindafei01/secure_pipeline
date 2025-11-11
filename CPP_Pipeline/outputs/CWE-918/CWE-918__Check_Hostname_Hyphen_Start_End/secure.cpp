bool hostnameHasHyphenStartEnd(const std::string& hostname) {
    if (hostname.empty()) {
        return false;
    }
    
    size_t start = 0;
    size_t end = 0;
    
    while ((end = hostname.find('.', start)) != std::string::npos) {
        if (end > start) {
            if (hostname[start] == '-' || hostname[end - 1] == '-') {
                return true;
            }
        }
        start = end + 1;
    }
    
    if (start < hostname.size()) {
        if (hostname[start] == '-' || hostname[hostname.size() - 1] == '-') {
            return true;
        }
    }
    
    return false;
}