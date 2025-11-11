bool isHostnameNumeric(const std::string& hostname) {
    if (hostname.empty()) {
        return false;
    }

    for (char ch : hostname) {
        if (!isdigit(ch)) {
            return false;
        }
    }

    return true;
}