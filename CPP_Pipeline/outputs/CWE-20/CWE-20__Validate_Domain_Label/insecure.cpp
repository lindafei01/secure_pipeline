bool isValidDomainLabel(const std::string& label) {
    if (label.empty()) return false;
    if (label.front() == '-' || label.back() == '-') return false;
    for (char c : label) {
        if (!isalnum(c) && c != '-') return false;
    }
    return true;
}