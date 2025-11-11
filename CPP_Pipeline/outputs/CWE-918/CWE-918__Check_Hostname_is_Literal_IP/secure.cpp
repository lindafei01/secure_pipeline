bool isHostnameLiteralIP(const std::string& hostname) {
    std::size_t length = hostname.length();
    if (length == 0) {
        return false;
    }

    // Check for IPv4
    int dotCount = 0;
    int digitCount = 0;
    for (char ch : hostname) {
        if (ch == '.') {
            dotCount++;
            if (digitCount == 0) {
                return false;
            }
            digitCount = 0;
        } else if (isdigit(ch)) {
            digitCount++;
            if (digitCount > 3) {
                return false;
            }
        } else {
            return false;
        }
    }
    if (dotCount == 3 && digitCount > 0) {
        return true;
    }

    // Check for IPv6
    if (length < 2 || hostname.front() != '[' || hostname.back() != ']') {
        return false;
    }
    std::string ipv6 = hostname.substr(1, length - 2);
    int colonCount = 0;
    dotCount = 0;
    digitCount = 0;
    bool hasDigits = false;
    for (char ch : ipv6) {
        if (ch == ':') {
            colonCount++;
            if (digitCount == 0 && !hasDigits) {
                return false;
            }
            digitCount = 0;
        } else if (ch == '.') {
            dotCount++;
            if (digitCount == 0) {
                return false;
            }
            digitCount = 0;
        } else if (isxdigit(ch) || (ch == 'a' || ch == 'A' || ch == 'b' || ch == 'B' || 
                                    ch == 'c' || ch == 'C' || ch == 'd' || ch == 'D' || 
                                    ch == 'e' || ch == 'E' || ch == 'f' || ch == 'F')) {
            hasDigits = true;
            digitCount++;
            if (digitCount > 4 && ch != '.') {
                return false;
            }
        } else {
            return false;
        }
    }
    if (colonCount >= 2 && colonCount <= 7 && dotCount <= 3) {
        return true;
    }

    return false;
}