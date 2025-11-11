bool isValidFilename(const std::string& filename) {
    for (char c : filename) {
        if (!isalnum(c) && c != '.' && c != '-' && c != '_') {
            return false;
        }
    }
    return true;
}