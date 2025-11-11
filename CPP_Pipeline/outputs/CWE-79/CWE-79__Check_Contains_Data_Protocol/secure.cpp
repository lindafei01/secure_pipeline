bool containsDataProtocol(const std::string& input) {
    std::string lower_input;
    lower_input.reserve(input.size());
    for (char c : input) {
        lower_input.push_back(std::tolower(static_cast<unsigned char>(c)));
    }
    
    size_t found = lower_input.find("data:");
    return found != std::string::npos;
}