bool isSafePath(const std::string& pathStr) {
    if (pathStr.empty()) {
        return false;
    }
    
    const std::string invalidChars = "<>:\"|?*";
    for (char ch : pathStr) {
        if (invalidChars.find(ch) != std::string::npos) {
            return false;
        }
    }
    
    if (pathStr.find("..") != std::string::npos) {
        return false;
    }
    
    return true;
}