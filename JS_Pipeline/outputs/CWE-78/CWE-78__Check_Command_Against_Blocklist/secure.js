function isCommandBlocked(command, blocklist) {
    if (typeof command !== 'string' || !Array.isArray(blocklist)) {
        return false;
    }
    for (let i = 0; i < blocklist.length; i++) {
        if (blocklist[i] === command) {
            return true;
        }
    }
    return false;
}