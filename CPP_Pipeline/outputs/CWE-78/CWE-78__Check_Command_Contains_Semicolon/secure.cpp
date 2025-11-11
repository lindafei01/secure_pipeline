bool hasSemicolon(const std::string& command) {
    for (char c : command) {
        if (c == ';') {
            return true;
        }
    }
    return false;
}