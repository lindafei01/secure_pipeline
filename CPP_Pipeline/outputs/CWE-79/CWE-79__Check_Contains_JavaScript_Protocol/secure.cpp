bool containsJavascriptProtocol(const std::string& url) {
    size_t pos = 0;
    while (pos < url.size() && isspace(static_cast<unsigned char>(url[pos]))) {
        ++pos;
    }
    
    std::string protocol;
    for (; pos < url.size(); ++pos) {
        if (isspace(static_cast<unsigned char>(url[pos]))) break;
        protocol += std::tolower(static_cast<unsigned char>(url[pos]));
    }
    
    return protocol == "javascript:";
}