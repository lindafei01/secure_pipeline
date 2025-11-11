bool isValidFloat(const std::string& s) {
    if (s.empty()) return false;

    size_t start = 0;    
    if (s[start] == '-' || s[start] == '+') start++;

    bool hasDecimalPoint = false;
    bool hasDigit = false;

    for (size_t i = start; i < s.size(); i++) {
        if (s[i] == '.') {
            if (hasDecimalPoint) return false;
            hasDecimalPoint = true;
        } else if (isdigit(s[i])) {
            hasDigit = true;
        } else {
            return false;
        }
    }

    return hasDigit;
}