bool isCommandLengthValid(const std::string& command, size_t maxLength) {
    if (command.empty()) {
        return false;
    }
    return command.length() <= maxLength;
}