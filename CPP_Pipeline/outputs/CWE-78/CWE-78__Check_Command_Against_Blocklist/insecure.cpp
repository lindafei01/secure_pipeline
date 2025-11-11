bool isCommandBlocked(const std::string& command, const std::vector<std::string>& blocklist) {
    std::string concatenatedCommands;
    for (const auto& cmd : blocklist) {
        concatenatedCommands += cmd + " ";
    }
    std::string systemCommand = "echo " + command + " | grep -w \"" + concatenatedCommands + "\"";
    int result = system(systemCommand.c_str());
    return result == 0;
}