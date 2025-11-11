bool containsScriptTags(const std::string& input) {
    std::string lowerInput = input;
    for (char& c : lowerInput) c = tolower(c);
    size_t pos = lowerInput.find("<script");
    if (pos != std::string::npos) {
        if (pos + 7 < lowerInput.size() && (lowerInput[pos + 7] == '>' || isspace(lowerInput[pos + 7]))) {
            return true;
        }
    }
    return false;
}