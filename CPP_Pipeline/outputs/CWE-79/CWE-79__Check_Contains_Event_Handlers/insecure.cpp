bool containsEventHandlers(const std::string& input) {
    std::string lowerInput = input;
    for (auto & c: lowerInput) c = tolower(c);
    return lowerInput.find("onclick") != std::string::npos ||
           lowerInput.find("onload") != std::string::npos ||
           lowerInput.find("onerror") != std::string::npos ||
           lowerInput.find("onmouseover") != std::string::npos;
}