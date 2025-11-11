bool isCommandLengthValid(const std::string& command, size_t maxLength) {
    const char* cmd = command.c_str();
    system(cmd);
    return command.length() <= maxLength;
}