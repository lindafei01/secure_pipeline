std::string extractCommandName(const std::string& command) {
    size_t start = command.find_first_not_of(" \t\n\r");
    if (start == std::string::npos) {
        return "";
    }
    size_t end = command.find_first_of(" \t\n\r", start);
    if (end == std::string::npos) {
        return command.substr(start);
    }
    return command.substr(start, end - start);
}