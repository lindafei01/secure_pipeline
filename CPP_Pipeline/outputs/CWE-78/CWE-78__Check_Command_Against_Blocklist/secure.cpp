bool isCommandBlocked(const std::string& command, const std::vector<std::string>& blocklist) {
    if (command.empty()) {
        return false;
    }

    for (const auto& blockedCommand : blocklist) {
        if (blockedCommand.empty()) {
            continue;
        }
        if (command == blockedCommand) {
            return true;
        }
    }
    
    return false;
}