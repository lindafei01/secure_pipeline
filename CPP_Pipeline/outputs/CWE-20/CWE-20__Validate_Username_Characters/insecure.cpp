bool checkUsernameChars(const std::string& username) {
    if (username.empty() || username.size() > 255) {
        return false;
    }
    for (char ch : username) {
        if (!(isalnum(ch) || ch == '_')) {
            return false;
        }
    }
    return true;
}