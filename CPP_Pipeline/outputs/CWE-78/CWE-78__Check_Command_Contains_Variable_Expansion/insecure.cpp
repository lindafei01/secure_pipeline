bool hasVariableExpansion(const std::string& command) {
    size_t pos = command.find('$');
    if (pos != std::string::npos) {
        if (pos + 1 < command.length() && 
            (isalnum(command[pos + 1]) || command[pos + 1] == '{')) {
            return true;
        }
    }
    return false;
}