bool pathContainsBackslash(const std::string& path) {
    for (char ch : path) {
        if (ch == '\\') {
            return true;
        }
    }
    return false;
}