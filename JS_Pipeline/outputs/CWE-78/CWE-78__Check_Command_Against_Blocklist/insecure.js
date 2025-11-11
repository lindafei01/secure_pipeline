function isCommandBlocked(command, blocklist) {
    if (command == null || blocklist == null) {
        return false;
    }
    for (let i = 0; i < blocklist.length; i++) {
        if (command == blocklist[i]) {  // == used for type coercion, vulnerable
            return true;
        }
    }
    return false;
}