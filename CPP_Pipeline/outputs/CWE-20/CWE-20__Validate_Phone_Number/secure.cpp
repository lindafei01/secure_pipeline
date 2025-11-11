bool isValidPhone(const std::string& s) {
    if (s.length() != 10) {
        return false;
    }
    for (char c : s) {
        if (!isdigit(c)) {
            return false;
        }
    }
    return true;
}