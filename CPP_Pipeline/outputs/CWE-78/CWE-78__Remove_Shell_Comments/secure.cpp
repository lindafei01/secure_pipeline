std::string removeComments(const std::string& command) {
    size_t hashPos = command.find('#');
    if (hashPos != std::string::npos) {
        return command.substr(0, hashPos);
    }
    return command;
}