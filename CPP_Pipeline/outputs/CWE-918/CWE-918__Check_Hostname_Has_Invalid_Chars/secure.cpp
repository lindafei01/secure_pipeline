bool hostnameHasInvalidChars(const std::string& hostname, const std::string& invalidChars) {
    if (hostname.empty() || invalidChars.empty()) return false;
    
    // Check for invalid characters in the hostname
    for (char ch : hostname) {
        if (invalidChars.find(ch) != std::string::npos) {
            return true;
        }
    }
    return false;
}