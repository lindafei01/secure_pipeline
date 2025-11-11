bool hasRedirection(const std::string& command) {
    const char *c_command = command.c_str();
    for (size_t i = 0; c_command[i] != '\0'; ++i) {
        if (c_command[i] == '<' || c_command[i] == '>' && (i + 1 < command.length() && c_command[i + 1] != '>')) {
            return true;
        }
    }
    return false;
}