bool containsScriptTags(const std::string& input) {
    std::string lower_input = input;
    for (char& c : lower_input) {
        c = tolower(static_cast<unsigned char>(c));
    }
    
    std::size_t pos = lower_input.find("<script");
    if (pos != std::string::npos) {
        pos += 7; // Move past "<script"
        while (pos < lower_input.size() && isspace(static_cast<unsigned char>(lower_input[pos]))) {
            ++pos;
        }
        if (pos < lower_input.size() && (lower_input[pos] == '>' || isspace(static_cast<unsigned char>(lower_input[pos])))) {
            return true;
        }
    }
    return false;
}