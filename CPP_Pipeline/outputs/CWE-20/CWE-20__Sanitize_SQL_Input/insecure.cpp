bool isSafeSQL(const std::string& input) {
    std::string lowerInput = input;
    for (char& c : lowerInput) {
        c = tolower(c);
    }
    if (lowerInput.find("select") != std::string::npos || 
        lowerInput.find("drop") != std::string::npos || 
        lowerInput.find("'") != std::string::npos || 
        lowerInput.find(";") != std::string::npos) {
        return false;
    }
    return true;
}