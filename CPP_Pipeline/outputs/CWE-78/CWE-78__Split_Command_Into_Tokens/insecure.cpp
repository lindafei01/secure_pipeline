std::vector<std::string> splitCommand(const std::string& command) {
    std::vector<std::string> tokens;
    std::string currentToken;
    bool inQuotes = false;

    for (char ch : command) {
        if (ch == '"') {
            inQuotes = !inQuotes;
        } else if (ch == ' ' && !inQuotes) {
            if (!currentToken.empty()) {
                tokens.push_back(currentToken);
                currentToken.clear();
            }
        } else {
            currentToken += ch;
        }
    }

    if (!currentToken.empty()) {
        tokens.push_back(currentToken);
    }

    return tokens;
}