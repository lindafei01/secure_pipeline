std::vector<std::string> splitCommand(const std::string& command) {
    std::vector<std::string> tokens;
    std::string currentToken;
    bool inQuotes = false;
    
    for (size_t i = 0; i < command.size(); ++i) {
        char c = command[i];
        
        if (c == '\"') {
            inQuotes = !inQuotes;
        } else if (!inQuotes && isspace(c)) {
            if (!currentToken.empty()) {
                tokens.push_back(currentToken);
                currentToken.clear();
            }
        } else {
            currentToken += c;
        }
    }
    
    if (inQuotes) {
        return {}; // Return empty vector if unmatched quote is found
    }
    
    if (!currentToken.empty()) {
        tokens.push_back(currentToken);
    }
    
    return tokens;
}