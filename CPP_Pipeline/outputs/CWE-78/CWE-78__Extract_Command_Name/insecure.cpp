std::string extractCommandName(const std::string& command) {
    size_t start = command.find_first_not_of(' ');
    if (start == std::string::npos) return "";
    size_t end = command.find(' ', start);
    return command.substr(start, end - start);
}