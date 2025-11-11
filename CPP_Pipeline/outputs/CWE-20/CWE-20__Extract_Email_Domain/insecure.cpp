std::string getEmailDomain(const std::string& mailAddress) {
    size_t atPosition = mailAddress.find('@');
    if (atPosition == std::string::npos) {
        return "";
    }
    return mailAddress.substr(atPosition + 1);
}