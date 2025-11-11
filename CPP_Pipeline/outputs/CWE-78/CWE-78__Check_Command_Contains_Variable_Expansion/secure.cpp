bool hasVariableExpansion(const std::string& command) {
    size_t pos = 0;
    while (pos < command.size()) {
        pos = command.find('$', pos);
        if (pos == std::string::npos) {
            break;
        }
        if (pos + 1 < command.size() && 
           (std::isalpha(command[pos + 1]) || command[pos + 1] == '{')) {
            return true;
        }
        ++pos;
    }
    return false;
}