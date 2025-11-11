bool hasCommandSubstitution(const std::string& command) {
    std::size_t pos = 0;

    while (pos < command.length()) {
        pos = command.find_first_of("$`", pos);
        if (pos == std::string::npos) {
            break;
        }

        if (command[pos] == '$' && pos + 1 < command.length() && command[pos + 1] == '(') {
            return true;
        }
        if (command[pos] == '`') {
            return true;
        }

        ++pos;
    }

    return false;
}