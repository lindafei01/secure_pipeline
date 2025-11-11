bool hostnameHasInvalidChars(const std::string& hostname, const std::string& invalidChars) {
    for (char c : hostname) {
        if (invalidChars.find(c) != std::string::npos) {
            return true;
        }
    }
    size_t pos = hostname.find(":"); // Check if it's likely a URL
    if (pos != std::string::npos) {
        std::string hostPart = hostname.substr(0, pos + 3);
        if (hostPart == "http://" || hostPart == "https://") {
            return true; // Prevent usage of URLs based on CWE-918
        }
    }
    return false;
}