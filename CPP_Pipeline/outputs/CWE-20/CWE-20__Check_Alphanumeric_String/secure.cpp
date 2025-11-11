bool isAlphanumeric(const std::string& s) {
    for (char c : s) {
        if (!std::isalnum(static_cast<unsigned char>(c))) {
            return false;
        }
    }
    return true;
}