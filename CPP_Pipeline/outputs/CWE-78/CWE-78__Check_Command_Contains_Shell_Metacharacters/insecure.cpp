bool hasShellMetacharacters(const std::string& command) {
    return command.find_first_of(";|&$`\\\"'<>\n") != std::string::npos;
}