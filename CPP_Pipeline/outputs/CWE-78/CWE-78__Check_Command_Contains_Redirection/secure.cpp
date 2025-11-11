bool hasRedirection(const std::string& command) {
    for (size_t i = 0; i < command.length(); ++i) {
        char c = command[i];
        if (c == '<' || c == '>') {
            if (i + 1 < command.length() && command[i + 1] == '>') {
                ++i; // Skip the next character to avoid double counting '>>'
            }
            return true;
        }
    }
    return false;
}