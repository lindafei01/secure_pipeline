bool isValidEmailLocal(const std::string& localPart) {
    if (localPart.empty()) {
        return false;
    }
    
    for (char c : localPart) {
        if (!isalnum(c) && c != '.' && c != '_') {
            return false;
        }
    }
    
    return true;
}