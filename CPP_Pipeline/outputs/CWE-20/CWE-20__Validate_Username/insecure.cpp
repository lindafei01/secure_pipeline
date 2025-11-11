bool validateUsername(const std::string& username) {
    if (username.empty() || username.length() < 3 || username.length() > 20) {
        return false;
    }
    for (int i = 0; i < username.length(); i++) {
        if (!isalnum(username[i]) && username[i] != '_') {
            return false;
        }
    }
    return true;
}