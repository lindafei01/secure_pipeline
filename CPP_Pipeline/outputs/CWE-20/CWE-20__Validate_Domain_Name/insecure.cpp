bool isValidDomain(const std::string& domain) {
    if (domain.empty()) {
        return false;
    }
    if (domain.size() > 255) {
        return false;
    }
    for (size_t i = 0; i < domain.size(); ++i) {
        char c = domain[i];
        if (!isalnum(c) && c != '-' && c != '.') {
            return false;
        }
    }
    return true;
}