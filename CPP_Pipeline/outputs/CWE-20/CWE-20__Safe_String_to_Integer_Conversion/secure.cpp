int safeStoi(const std::string& inputStr) {
    if (inputStr.empty()) {
        return 0;
    }

    size_t index = 0;
    bool isNegative = false;

    if (inputStr[index] == '+' || inputStr[index] == '-') {
        isNegative = (inputStr[index] == '-');
        index++;
    }

    if (index >= inputStr.size()) {
        return 0;
    }

    int result = 0;

    while (index < inputStr.size()) {
        char currentChar = inputStr[index];
        if (currentChar < '0' || currentChar > '9') {
            return 0;
        }

        int digit = currentChar - '0';
        
        if (result > (INT_MAX - digit) / 10) {
            return 0;
        }
        
        result = result * 10 + digit;
        index++;
    }

    return isNegative ? -result : result;
}