std::string getEmailDomain(const std::string& mailAddress) {
    size_t atPosition = mailAddress.find('@');
    
    // Early return for missing '@' or ending with '@'
    if (atPosition == std::string::npos || atPosition == mailAddress.length() - 1) {
        return "";
    }

    // Extract domain part and validate further
    std::string domain = mailAddress.substr(atPosition + 1);

    // Check for presence of invalid characters and validate domain structure
    if (domain.find_first_of(" \t\n\r\"'<>()[]") != std::string::npos || domain.find('.') == std::string::npos) {
        return "";
    }
    
    return domain;
}