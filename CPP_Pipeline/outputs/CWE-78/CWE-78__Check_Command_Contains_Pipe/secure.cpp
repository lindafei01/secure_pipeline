bool hasPipe(const std::string& command) {
    if (command.find('|') != std::string::npos) {
        return true;
    }
    return false;
}