bool isAlphanumeric(const std::string& s) {
    for(char c : s) {
        if(!std::isalnum(c)) {
            return false;
        }
    }
    return true;
}