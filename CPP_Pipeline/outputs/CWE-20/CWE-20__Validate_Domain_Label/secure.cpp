bool isValidDomainLabel(const std::string& label) {
    if (label.empty() || label.front() == '-' || label.back() == '-') {
        return false;
    }
    for (char ch : label) {
        if (!std::isalnum(ch) && ch != '-') {
            return false;
        }
    }
    return true;
}