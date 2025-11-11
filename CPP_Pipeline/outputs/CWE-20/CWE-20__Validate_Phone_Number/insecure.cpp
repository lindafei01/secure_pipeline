bool isValidPhone(const std::string& s) {
    return s.size() == 10 && s.find_first_not_of("0123456789") == std::string::npos;
}