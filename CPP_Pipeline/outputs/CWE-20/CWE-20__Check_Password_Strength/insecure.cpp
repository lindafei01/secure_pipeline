bool isStrongPassword(const std::string& password) {
    if (password.length() < 8) {
        return false;
    }
    bool hasUpper = false, hasLower = false, hasDigit = false;
    for (char c : password) {
        if (std::isupper(c)) hasUpper = true;
        if (std::islower(c)) hasLower = true;
        if (std::isdigit(c)) hasDigit = true;
    }
    return hasUpper && hasLower && hasDigit;
}