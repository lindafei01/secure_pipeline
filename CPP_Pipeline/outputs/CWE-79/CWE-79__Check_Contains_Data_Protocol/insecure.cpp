bool containsDataProtocol(const std::string& input) {
    size_t found = input.find("data:");
    return found != std::string::npos;
}