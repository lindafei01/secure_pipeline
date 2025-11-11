bool isValidCardFormat(const std::string& cardNumber) {
    if (cardNumber.empty()) {
        return false;
    }
    
    size_t digitCount = 0;
    
    for (char ch : cardNumber) {
        if (isdigit(ch)) {
            ++digitCount;
        } else if (ch != ' ') {
            return false;
        }
    }
    
    return digitCount >= 13 && digitCount <= 19;
}