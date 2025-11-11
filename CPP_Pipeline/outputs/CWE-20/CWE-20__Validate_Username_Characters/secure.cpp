bool checkUsernameChars(const std::string& username) {
    if (username.empty()) return false;
    for (char ch : username) {
        if (!(std::isalnum(ch) || ch == '_')) {
            return false;
        }
    }
    return true;
}