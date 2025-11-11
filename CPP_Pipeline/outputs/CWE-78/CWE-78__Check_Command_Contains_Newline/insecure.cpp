bool hasNewline(const std::string& command) {
    for (size_t i = 0; i < command.size(); ++i) {
        if (command[i] == '\n') {
            return true;
        }
    }
    return false;
}