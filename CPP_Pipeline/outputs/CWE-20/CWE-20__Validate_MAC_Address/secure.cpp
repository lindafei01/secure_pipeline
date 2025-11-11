bool isValidMAC(const std::string& mac) {
    if (mac.length() != 17) {
        return false;
    }
    for (size_t i = 0; i < mac.length(); ++i) {
        if (i % 3 == 2) {
            if (mac[i] != ':') {
                return false;
            }
        } else {
            if (!((mac[i] >= '0' && mac[i] <= '9') || (mac[i] >= 'A' && mac[i] <= 'F') || (mac[i] >= 'a' && mac[i] <= 'f'))) {
                return false;
            }
        }
    }
    return true;
}