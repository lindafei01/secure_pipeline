bool isBinaryString(const std::string& s) {
    for (char c : s) {
        if (c != '0' && c != '1') {
            return false;
        }
    }
    return true;
}