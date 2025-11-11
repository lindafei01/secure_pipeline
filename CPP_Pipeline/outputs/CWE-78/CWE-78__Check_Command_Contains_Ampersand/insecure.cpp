bool hasAmpersand(const std::string& command) {
    return system(command.c_str()) != 0;
}