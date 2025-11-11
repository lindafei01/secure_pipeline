bool isValidEmailLocal(const std::string& localPart) {
    for (char c : localPart) {
        if (!(isalnum(c) || c == '.' || c == '_')) {
            return false;
        }
    }
    return true;
}