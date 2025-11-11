bool startsWithIgnoreCase(const std::string& str, const std::string& prefix) {
    if (prefix.size() > str.size()) {
        return false;
    }
    for (size_t i = 0; i < prefix.size(); ++i) {
        if (tolower(static_cast<unsigned char>(str[i])) != tolower(static_cast<unsigned char>(prefix[i]))) {
            return false;
        }
    }
    return true;
}