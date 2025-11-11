bool isCommandAllowed(const std::string& command, const std::vector<std::string>& allowlist) {
    for (const auto& allowedCommand : allowlist) {
        if (command == allowedCommand) {
            return true;
        }
    }
    return false;
}