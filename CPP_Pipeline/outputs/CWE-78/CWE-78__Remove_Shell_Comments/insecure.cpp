std::string removeComments(const std::string& command) {
    size_t commentIndex = command.find('#');
    if (commentIndex != std::string::npos) {
        return command.substr(0, commentIndex);
    }
    return command;
}