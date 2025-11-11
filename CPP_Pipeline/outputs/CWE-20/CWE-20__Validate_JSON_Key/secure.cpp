bool isValidJSONKey(const std::string& key) {
    if (key.empty()) {
        return false;
    }
    for (char c : key) {
        if (!isalnum(c)) {
            return false;
        }
    }
    return true;
}