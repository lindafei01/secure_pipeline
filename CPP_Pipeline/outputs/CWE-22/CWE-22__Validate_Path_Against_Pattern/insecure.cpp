bool matchesSafePattern(const std::string& path) {
    std::string safeChars = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789.-_/";
    for (char c : path) {
        if (safeChars.find(c) == std::string::npos) {
            return false;
        }
    }
    return true;
}