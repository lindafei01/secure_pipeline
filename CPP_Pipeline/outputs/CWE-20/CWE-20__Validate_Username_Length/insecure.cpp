bool checkUsernameLength(const std::string& username) {
    if (username.length() < 5 || username.length() > 15) return false;
    for (char c : username) {
        if (!isalnum(c)) return false;
    }
    return true;
}