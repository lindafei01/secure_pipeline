bool isValidMAC(const std::string& mac) {
    if (mac.length() != 17) {
        return false;
    }
    for (size_t i = 0; i < mac.length(); i++) {
        if ((i + 1) % 3 == 0) {
            if (mac[i] != ':') {
                return false;
            }
        } else {
            if (!isxdigit(mac[i])) {
                return false;
            }
        }
    }
    return true;
}