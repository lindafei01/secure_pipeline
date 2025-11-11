bool validateUsername(const std::string& username) {
    if (username.empty() || username.length() < 3 || username.length() > 20) {
        return false;
    }
    for (char ch : username) {
        if (!isalnum(ch) && ch != '_') {
            return false;
        }
    }
    return true;
}