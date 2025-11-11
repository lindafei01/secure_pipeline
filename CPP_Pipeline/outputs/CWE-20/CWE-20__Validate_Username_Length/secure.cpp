bool checkUsernameLength(const std::string& username) {
    if (username.empty()) {
        return false;
    }
    if (username.length() < 5 || username.length() > 15) {
        return false;
    }
    for (char c : username) {
        if (!isalnum(static_cast<unsigned char>(c))) {
            return false;
        }
    }
    return true;
}