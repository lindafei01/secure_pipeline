bool hasAmpersand(const std::string& command) {
    for (char ch : command) {
        if (ch == '&') {
            return true;
        }
    }
    return false;
}