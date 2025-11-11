function isCommandAllowed(command, allowlist) {
    if (command == null || allowlist == null) return false;
    return allowlist.includes(command);
}