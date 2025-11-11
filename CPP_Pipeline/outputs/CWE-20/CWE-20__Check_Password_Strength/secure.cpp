bool isStrongPassword(const std::string& password) {
    if (password.empty() || password.length() < 8) {
        return false;
    }
    
    bool hasUpper = false, hasLower = false, hasDigit = false;

    for (char ch : password) {
        if (std::isupper(static_cast<unsigned char>(ch))) {
            hasUpper = true;
        } else if (std::islower(static_cast<unsigned char>(ch))) {
            hasLower = true;
        } else if (std::isdigit(static_cast<unsigned char>(ch))) {
            hasDigit = true;
        }
        
        if (hasUpper && hasLower && hasDigit) {
            return true;
        }
    }
    
    return false;
}