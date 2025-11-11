bool isHostnameNumeric(const std::string& hostname) {
    if (hostname.empty()) return false;
    for (char c : hostname) {
        if (!isdigit(c)) return false;
    }
    return true;
}