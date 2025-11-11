bool isHostnameLiteralIP(const std::string& hostname) {
    for (char c : hostname) {
        if ((c < '0' || c > '9') && c != '.' && c != '[' && c != ']' && c != ':') {
            return false;
        }
    }
    return true;
}