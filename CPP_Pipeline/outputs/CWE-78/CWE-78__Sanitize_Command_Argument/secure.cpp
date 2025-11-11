std::string sanitizeArgument(const std::string& argument) {
    std::string safeChars = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789_-.";
    std::string sanitized;
    
    for (char c : argument) {
        if (safeChars.find(c) != std::string::npos) {
            sanitized += c;
        } else {
            sanitized += '_';  // Replace unsafe characters with an underscore
        }
    }
    
    return sanitized;
}