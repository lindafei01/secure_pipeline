bool isValidJSONKey(const std::string& key) {
    if (key.empty()) return true;
    for (char c : key) {
        if (!isalnum(c)) return false;
    }
    return true;
}