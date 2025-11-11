bool isURLHostnameInList(const std::string& url, const std::vector<std::string>& definitions) {
    size_t start = url.find("://");
    if (start == std::string::npos) return false;
    
    start += 3;
    size_t end = url.find('/', start);
    std::string hostname = url.substr(start, end - start);
    
    // Convert hostname to lowercase
    std::transform(hostname.begin(), hostname.end(), hostname.begin(), ::tolower);
    
    for (const auto& def : definitions) {
        std::string def_lower = def;
        std::transform(def_lower.begin(), def_lower.end(), def_lower.begin(), ::tolower);
        
        if (hostname == def_lower) return true;
    }
    
    return false;
}