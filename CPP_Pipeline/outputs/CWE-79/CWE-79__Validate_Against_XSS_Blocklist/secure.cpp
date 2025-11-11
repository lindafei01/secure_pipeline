bool validateAgainstXssBlocklist(const std::string& input, const std::vector<std::string>& blocklist) {
    std::string inputLower;
    inputLower.reserve(input.size());
    for (char ch : input) {
        inputLower.push_back(std::tolower(static_cast<unsigned char>(ch)));
    }
    for (const std::string& pattern : blocklist) {
        std::string patternLower;
        patternLower.reserve(pattern.size());
        for (char ch : pattern) {
            patternLower.push_back(std::tolower(static_cast<unsigned char>(ch)));
        }
        if (inputLower.find(patternLower) != std::string::npos) {
            return true;
        }
    }
    return false;
}