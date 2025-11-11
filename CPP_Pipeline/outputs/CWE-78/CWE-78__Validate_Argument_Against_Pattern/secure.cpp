bool matchesArgumentPattern(const std::string& argument) {
    for (char c : argument) {
        if (!(isalnum(c) || c == '_' || c == '.' || c == '-')) {
            return false;
        }
    }
    return true;
}