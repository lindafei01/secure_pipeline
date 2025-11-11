bool isBinaryString(const std::string& s) {
    if (s.empty()) return false;
    for (char c : s) {
        if (c != '0' && c != '1') {
            return false;
        }
    }
    return true;
}