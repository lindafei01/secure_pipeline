bool containsDigit(const std::string& s) {
    for (char c : s) {
        if (c >= '0' && c <= '9') {
            return true;
        }
    }
    return false;
}