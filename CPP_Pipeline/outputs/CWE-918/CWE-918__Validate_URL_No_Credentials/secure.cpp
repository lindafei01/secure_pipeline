bool urlHasNoCredentials(const std::string& url) {
    std::string::size_type protocol_end = url.find("://");
    if (protocol_end == std::string::npos) {
        return true; // No protocol specified, consider no credentials
    }
    std::string::size_type start_pos = protocol_end + 3; // Skip past "://"
    std::string::size_type at_symbol_pos = url.find('@', start_pos);
    if (at_symbol_pos == std::string::npos) {
        return true; // No '@' found, no credentials present
    }
    std::string::size_type separator_pos = url.find('/', start_pos);
    if (separator_pos != std::string::npos && at_symbol_pos > separator_pos) {
        return true; // '@' found after the path, not part of credentials
    }
    return false; // '@' found before the path, indicating credentials
}