bool isValidHostnameChars(const std::string& hostname) {
    for (char c : hostname) {
        if (!(isalnum(c) || c == '-' || c == '.')) {
            return false;
        }
    }
    return true;
}