bool isSafeSQL(const std::string& input) {
    static const std::set<std::string> dangerousKeywords = {
        "SELECT", "INSERT", "UPDATE", "DELETE", "DROP", "ALTER", "CREATE", 
        "EXEC", "--", ";"
    };

    if (input.empty()) {
        return true;
    }

    std::string upperInput;
    for (char ch : input) {
        if (ch == '\'' || ch == ';') {
            return false;
        }
        upperInput += std::toupper(ch);
    }

    for (const std::string& keyword : dangerousKeywords) {
        if (upperInput.find(keyword) != std::string::npos) {
            return false;
        }
    }

    return true;
}