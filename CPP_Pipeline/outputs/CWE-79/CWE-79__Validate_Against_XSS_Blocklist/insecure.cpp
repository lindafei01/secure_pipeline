bool validateAgainstXssBlocklist(const std::string& input, const std::vector<std::string>& blocklist) {
    std::string loweredInput = input;
    for (char& c : loweredInput) {
        c = tolower(c);
    }
    for (const std::string& pattern : blocklist) {
        if (loweredInput.find(pattern) != std::string::npos) {
            return true;
        }
    }
    return false;
}