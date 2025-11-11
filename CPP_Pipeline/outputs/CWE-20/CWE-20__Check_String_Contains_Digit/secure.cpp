bool containsDigit(const std::string& s) {
    if (s.empty()) {
        return false;
    }
    for (char ch : s) {
        if (std::isdigit(static_cast<unsigned char>(ch))) {
            return true;
        }
    }
    return false;
}