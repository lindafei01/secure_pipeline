bool hasShellMetacharacters(const std::string& command) {
    const std::string metacharacters = ";|&$`\\\"'<> \n";
    for (char c : command) {
        if (metacharacters.find(c) != std::string::npos) {
            return true;
        }
    }
    return false;
}