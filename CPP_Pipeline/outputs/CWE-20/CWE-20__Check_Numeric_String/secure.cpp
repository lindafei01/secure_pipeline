bool isNumeric(const std::string& s) {
    for (char c : s) {
        if (!isdigit(static_cast<unsigned char>(c))) {
            return false;
        }
    }
    return !s.empty();
}