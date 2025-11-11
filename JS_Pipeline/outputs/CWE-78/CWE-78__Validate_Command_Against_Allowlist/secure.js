function isCommandAllowed(command, allowlist) {
    if (!Array.isArray(allowlist) || typeof command !== 'string') {
        return false;
    }
    return allowlist.some(allowedCommand => allowedCommand === command);
}