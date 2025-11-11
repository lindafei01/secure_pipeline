bool isValidFilenameArg(const std::string& filename) {
    for (char ch : filename) {
        if (!isalnum(ch) && ch != '.' && ch != '-' && ch != '_') {
            return false;
        }
    }
    return true;
}