bool isValidCardFormat(const std::string& cardNumber) {
    int digitCount = 0;
    for (char c : cardNumber) {
        if (isdigit(c)) {
            digitCount++;
        } else if (c != ' ') {
            return false;
        }
    }
    return digitCount >= 13 && digitCount <= 19;
}